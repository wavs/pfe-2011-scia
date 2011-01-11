#include <iostream>
#include <vector>
#include "server.h"
#include "OpenCV/cv.h"
#include "OpenCV/highgui.h"
#include "OpenCV/cxcore.h"

////////////////////////////////////////////////////////////////////////////////

const int SEUIL_BINAIRE = 30;
const int DILATE_RADIUS = 10;
const int MAX_XY        = 32000;
const int MIN_SZ        = 2;
const int MAX_SZ        = 80;
const int MAX_RATIO     = 80;

////////////////////////////////////////////////////////////////////////////////

void DetectAndDraw(IplImage* frame, Server& server)
{
  double t = (double)cvGetTickCount();

  IplImage* img_nvg = cvCreateImage(cvGetSize(frame), frame->depth, 1);
  IplImage* img_imp = cvCloneImage(img_nvg);

  // Niveau de gris puis binarisation
  cvConvertImage(frame, img_nvg, (frame->origin!=IPL_ORIGIN_TL) ? CV_CVTIMG_FLIP : 0);
  cvThreshold(img_nvg, img_imp, SEUIL_BINAIRE, 255, CV_THRESH_BINARY_INV);

  // dilatation puis erosion
  IplConvKernel* noyau = cvCreateStructuringElementEx(DILATE_RADIUS,
                                                      DILATE_RADIUS,
                                                      DILATE_RADIUS/2,
                                                      DILATE_RADIUS/2,
                                                      CV_SHAPE_ELLIPSE);
  cvDilate(img_imp, img_imp, noyau);
  cvErode(img_imp,  img_imp, noyau);

  // Detection des formes
  CvMemStorage* storage = cvCreateMemStorage(0);
  CvSeq* contour = NULL;
  cvFindContours(img_imp, storage, &contour, sizeof(CvContour));

  // Calcul du centre des doigts et envoie au server
  std::vector<Pos2d> positions;
  for(;contour != 0; contour = contour->h_next)
  {
    int max_x = -1, max_y = -1, min_x = MAX_XY, min_y = MAX_XY;
    for(int i = 0; i < contour->total; ++i)
    {
      CvPoint* p = CV_GET_SEQ_ELEM(CvPoint, contour, i);
      if (p->x > max_x) max_x = p->x;
      if (p->y > max_y) max_y = p->y;
      if (p->x < min_x) min_x = p->x;
      if (p->y < min_y) min_y = p->y;
    }

    CvPoint center;
    Pos2d pos((max_x + min_x) / 2, (max_y + min_y) / 2);
    center.x = pos.x;
    center.y = pos.y;
    positions.push_back(pos);

    int szx = max_x - min_x, szy = max_y - min_y;
    if (szx > MIN_SZ && szy > MIN_SZ &&
        szx < MAX_SZ && szy < MAX_SZ &&
        szx / (float)szy < MAX_RATIO &&
        szy / (float) szx < MAX_RATIO)
      cvCircle(frame, center, 16, CV_RGB(255,0,0));
  }
  server.SendPos(positions);

  // Liberation de la memoire
  cvReleaseMemStorage(&storage);
  cvReleaseImage(&img_nvg);
  cvReleaseImage(&img_imp);

  // Calcul du temps ecoulé et affichage de l'image
  t = (double)cvGetTickCount() - t;
  std::cout << "detection time = " << t/((double)cvGetTickFrequency()*1000.) << "ms" << std::endl;

  cvShowImage("result", frame);
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char* argv[])
{
  // Init server
  Server server;
  if (!server.Init())
  {
    std::cout << "Error : Can't initialize server" << std::endl;
    return 1;
  }

  // Init webcam
  CvCapture* capture = cvCaptureFromCAM(0);
  if(capture == NULL)
  {
    std::cout << "Error : Can't find webcam" << std::endl;
    return 2;
  }

  cvNamedWindow("result", CV_WINDOW_AUTOSIZE);
  // Start detect
  while (cvWaitKey(20)!=' ')
  {
    IplImage* frame = cvQueryFrame(capture);

    Mat frame_test = frame;
    if(frame_test.empty())
    {
      std::cout << "Error : Empty frame" << std::endl;
      return 3;
    }
    DetectAndDraw(frame, server);
    //cvReleaseImage(&frame);
  }

  cvDestroyWindow("result");
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
