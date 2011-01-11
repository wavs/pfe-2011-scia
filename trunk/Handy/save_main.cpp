#define CV_NO_BACKWARD_COMPATIBILITY

#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <string>


#include "OpenCV/cv.h"
#include "OpenCV/highgui.h"



#define PORT        5542
/* REPLACE with your server machine name*/
#define HOST        "localhost"
#define CLOSE		"close"
#define MSG_SIZE	100
#define DIRSIZE     8192
#define BACKLOG 1


using namespace std;
using namespace cv;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// creating the server component

char hostname[100];
char    dir[DIRSIZE];
int sd;
int conn;
int size_recv;
char message[100];
struct sockaddr_in ssin;
struct hostent *hp;



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// various tracking parameters (in seconds)
const double MHI_DURATION = 1;
const double MAX_TIME_DELTA = 0.5;
const double MIN_TIME_DELTA = 0.05;
// number of cyclic frame buffer used for motion detection
// (should, probably, depend on FPS)
const int N = 4;

// ring image buffer
IplImage **buf = 0;
int last = 0;

// temporary images
IplImage *mhi = 0; // MHI
IplImage *orient = 0; // orientation
IplImage *mask = 0; // valid orientation mask
IplImage *segmask = 0; // motion segmentation map
CvMemStorage* storage = 0; // temporary storage


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// creating the server
int init_server(void)
{
	strcpy((char*)hostname, (const char*)HOST);
	
	
	/* go find out about the desired host machine */
	
	 if ((hp = gethostbyname(hostname)) == 0) {
	 perror("gethostbyname");
	 return(-1);
	 }
	
	/* fill in the socket structure with host information */
	

	 
	memset(&ssin, 0, sizeof (struct sockaddr_in));
	ssin.sin_addr.s_addr = htonl(INADDR_ANY);
	ssin.sin_family = PF_INET;
	ssin.sin_port = htons(PORT);
	
	 /* grab an Internet domain socket */
	
	 if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
	 perror("socket");
	 return(-1);
	 }
	
	
	/* connect to PORT on HOST */
	
	 if (bind(sd,(struct sockaddr *)  &ssin, sizeof(ssin)) == -1) {
	 perror("connect");
		 close(sd);
	 return(-1);
	 }
	 
	 if (listen(sd, BACKLOG) == -1)
	 {
	 perror("couldn't not connect");
		 close(sd);
	 return(-1);
	 }
	
	
	
	struct sockaddr_in ppin;
	socklen_t ss_sister = sizeof (struct sockaddr);
	conn = accept(sd, (struct sockaddr *)&ppin, &ss_sister);
	 if (conn == -1)
	 {
	 perror("accept failed");
		 close(sd);
	 return(-1);
	 }
	
	memset(&message, 0, MSG_SIZE);


	
	size_recv = recv(conn, message, MSG_SIZE, MSG_PEEK);
	if ( size_recv == -1)
	{
			 perror("didn't received message");
		close(sd);
			 return (-1);
	}
	else if ( size_recv == 0)
	{
		perror("the peer closed the connexion");
		close(sd);
		return (-1);
	}
	else {
		std::cout << message << std::endl;
	}
 
	return (0);
	 	
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void close_connection()
{
	
	/// close the socket and send message
	if (send(conn, (const void*)CLOSE, 5, MSG_EOR) == -1)
	{
		perror("Cannot send CLOSE message");
		close(conn);
	}
	
	recv(conn, message, MSG_SIZE, MSG_PEEK);
	close(conn);
	return;
}


void  update_mhi( IplImage* img, IplImage* dst, int diff_threshold )
{
    double timestamp = (double)clock()/CLOCKS_PER_SEC; // get current time in seconds
    CvSize size = cvSize(img->width,img->height); // get current frame size
    int i, idx1 = last, idx2;
    IplImage* silh;
    CvSeq* seq;
    CvRect comp_rect;
    double count;
    double angle;
    CvPoint center;
    double magnitude;
    CvScalar color;

    // allocate images at the beginning or
    // reallocate them if the frame size is changed
    if( !mhi || mhi->width != size.width || mhi->height != size.height ) {
        if( buf == 0 ) {
            buf = (IplImage**)malloc(N*sizeof(buf[0]));
            memset( buf, 0, N*sizeof(buf[0]));
        }

        for( i = 0; i < N; i++ ) {
            cvReleaseImage( &buf[i] );
            buf[i] = cvCreateImage( size, IPL_DEPTH_8U, 1 );
            cvZero( buf[i] );
        }
        cvReleaseImage( &mhi );
        cvReleaseImage( &orient );
        cvReleaseImage( &segmask );
        cvReleaseImage( &mask );

        mhi = cvCreateImage( size, IPL_DEPTH_32F, 1 );
        cvZero( mhi ); // clear MHI at the beginning
        orient = cvCreateImage( size, IPL_DEPTH_32F, 1 );
        segmask = cvCreateImage( size, IPL_DEPTH_32F, 1 );
        mask = cvCreateImage( size, IPL_DEPTH_8U, 1 );
    }

    cvCvtColor( img, buf[last], CV_BGR2GRAY ); // convert frame to grayscale

    idx2 = (last + 1) % N; // index of (last - (N-1))th frame
    last = idx2;

    silh = buf[idx2];
    cvAbsDiff( buf[idx1], buf[idx2], silh ); // get difference between frames

    cvThreshold( silh, silh, diff_threshold, 1, CV_THRESH_BINARY ); // and threshold it
    cvUpdateMotionHistory( silh, mhi, timestamp, MHI_DURATION ); // update MHI

    // convert MHI to blue 8u image
    cvCvtScale( mhi, mask, 255./MHI_DURATION,
                (MHI_DURATION - timestamp)*255./MHI_DURATION );
    cvZero( dst );
    cvMerge( mask, 0, 0, 0, dst );

    // calculate motion gradient orientation and valid orientation mask
    cvCalcMotionGradient( mhi, mask, orient, MAX_TIME_DELTA, MIN_TIME_DELTA, 3 );

    if( !storage )
        storage = cvCreateMemStorage(0);
    else
        cvClearMemStorage(storage);

    // segment motion: get sequence of motion components
    // segmask is marked motion components map. It is not used further
    seq = cvSegmentMotion( mhi, segmask, storage, timestamp, MAX_TIME_DELTA );

    // iterate through the motion components,
    // One more iteration (i == -1) corresponds to the whole image (global motion)
    for( i = -1; i < seq->total; i++ ) {

        if( i < 0 ) { // case of the whole image
            comp_rect = cvRect( 0, 0, size.width, size.height );
            color = CV_RGB(255,255,255);
            magnitude = 100;
        }
        else { // i-th motion component
            comp_rect = ((CvConnectedComp*)cvGetSeqElem( seq, i ))->rect;
            if( comp_rect.width + comp_rect.height < 100 ) // reject very small components
                continue;
            color = CV_RGB(255,0,0);
            magnitude = 30;
        }

        // select component ROI
        cvSetImageROI( silh, comp_rect );
        cvSetImageROI( mhi, comp_rect );
        cvSetImageROI( orient, comp_rect );
        cvSetImageROI( mask, comp_rect );

        // calculate orientation
        angle = cvCalcGlobalOrientation( orient, mask, mhi, timestamp, MHI_DURATION);
        angle = 360.0 - angle;  // adjust for images with top-left origin

        count = cvNorm( silh, 0, CV_L1, 0 ); // calculate number of points within silhouette ROI

        cvResetImageROI( mhi );
        cvResetImageROI( orient );
        cvResetImageROI( mask );
        cvResetImageROI( silh );

        // check for the case of little motion
        if( count < comp_rect.width*comp_rect.height * 0.05 )
            continue;

        // draw a clock with arrow indicating the direction
        center = cvPoint( (comp_rect.x + comp_rect.width/2),
                          (comp_rect.y + comp_rect.height/2) );

        cvCircle( dst, center, cvRound(magnitude*1.2), color, 3, CV_AA, 0 );
        cvLine( dst, center, cvPoint( cvRound( center.x + magnitude*cos(angle*CV_PI/180)),
                cvRound( center.y - magnitude*sin(angle*CV_PI/180))), color, 3, CV_AA, 0 );
    }
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


void detectAndDraw( Mat& img, IplImage* image,
                   CascadeClassifier& cascade, CascadeClassifier& nestedCascade,
                   double scale, IplImage* motion);

////////////////////////////////////////////////////////////////////////////////1
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


//<<<<<<< .mine
//String cascadeName = "/Users/gui/code/pfe-2011-scia/Handy/doigt.xml";
//=======
String cascadeName = "/Users/Alex/Documents/Programation/pfe/pfe-2011-scia/Handy/doigt.xml";
//>>>>>>> .r27
////"haarcascade_frontalface_alt.xml";
//String nestedCascadeName =
//<<<<<<< .mine
//"/Users/gui/code/pfe-2011-scia/Handy/haarcascade_eye_tree_eyeglasses.xml";
//=======
"/Users/Alex/Documents/Programation/pfe/pfe-2011-scia/Handy/haarcascade_eye_tree_eyeglasses.xml";
//>>>>>>> .r27

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


int main( int argc, const char** argv )
{
    CvCapture* capture = 0;
    Mat frame, frameCopy, image;
    const String scaleOpt = "--scale=";
    size_t scaleOptLen = scaleOpt.length();
    const String cascadeOpt = "--cascade=";
    size_t cascadeOptLen = cascadeOpt.length();
    const String nestedCascadeOpt = "--nested-cascade";
    size_t nestedCascadeOptLen = nestedCascadeOpt.length();
    String inputName;

    CascadeClassifier cascade, nestedCascade;
    double scale = 1;
	
    for( int i = 1; i < argc; i++ )
    {
        if( cascadeOpt.compare( 0, cascadeOptLen, argv[i], cascadeOptLen ) == 0 )
            cascadeName.assign( argv[i] + cascadeOptLen );
        else if( nestedCascadeOpt.compare( 0, nestedCascadeOptLen, argv[i], nestedCascadeOptLen ) == 0 )
        {
            if( argv[i][nestedCascadeOpt.length()] == '=' )
                nestedCascadeName.assign( argv[i] + nestedCascadeOpt.length() + 1 );
            if( !nestedCascade.load( nestedCascadeName ) )
                cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
        }
        else if( scaleOpt.compare( 0, scaleOptLen, argv[i], scaleOptLen ) == 0 )
        {
            if( !sscanf( argv[i] + scaleOpt.length(), "%lf", &scale ) || scale < 1 )
                scale = 1;
        }
        else if( argv[i][0] == '-' )
        {
            cerr << "WARNING: Unknown option %s" << argv[i] << endl;
        }
        else
            inputName.assign( argv[i] );
    }


    IplImage* motion = 0;


	// init server bitch!
	
	if (init_server() == -1)
	{
		perror("init server failed");
		return (-1);
	}

    if( !cascade.load( cascadeName ) )
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        cerr << "Usage: facedetect [--cascade=\"<cascade_path>\"]\n"
            "   [--nested-cascade[=\"nested_cascade_path\"]]\n"
            "   [--scale[=<image scale>\n"
            "   [filename|camera_index]\n" ;
		
		close_connection();

		
		// send close // wait for answer before close or if -1 close
		
        return -1;
    }

    if( inputName.empty() || (isdigit(inputName.c_str()[0]) && inputName.c_str()[1] == '\0') )
        capture = cvCaptureFromCAM( inputName.empty() ? 0 : inputName.c_str()[0] - '0' );
    else if( inputName.size() )
    {
        image = imread( inputName, 1 );
        if( image.empty() )
            capture = cvCaptureFromAVI( inputName.c_str() );
    }
    else
        image = imread( "lena.jpg", 1 );

    cvNamedWindow( "result", 1 );
    cvNamedWindow( "Motion", 1 );

    if( capture )
    {
		
		// we should send via socket here :D
        for(;;)
        {
            IplImage* iplImg = cvQueryFrame( capture );
            frame = iplImg;


            if( !motion )
            {
                motion = cvCreateImage( cvSize(iplImg->width,iplImg->height), 8, 3 );
                cvZero( motion );
                motion->origin = iplImg->origin;
            }
			
            if( frame.empty() )
                break;
            if( iplImg->origin == IPL_ORIGIN_TL )
                frame.copyTo( frameCopy );
            else
                flip( frame, frameCopy, 0 );

			// send
			// recv inside the detectAndDraw
            detectAndDraw( frameCopy, iplImg, cascade, nestedCascade, scale, motion);

            if( waitKey( 10 ) >= 0 )
                goto _cleanup_;
        }
		close_connection();
        waitKey(0);
_cleanup_:
		// send close // wait for answer before close or if -1 close
        cvReleaseCapture( &capture );
    }/*
    else
    {
        if( !image.empty() )
        {
            detectAndDraw( image, cascade, nestedCascade, scale, motion );
            waitKey(0);
        }
        else if( !inputName.empty() )
        {
            FILE* f = fopen( inputName.c_str(), "rt" );
            if( f )
            {
                char buf[1000+1];
                while( fgets( buf, 1000, f ) )
                {
                    int len = (int)strlen(buf), c;
                    while( len > 0 && isspace(buf[len-1]) )
                        len--;
                    buf[len] = '\0';
                    cout << "file " << buf << endl;
                    image = imread( buf, 1 );
                    if( !image.empty() )
                    {
                        detectAndDraw( image, cascade, nestedCascade, scale, motion );
                        c = waitKey(0);
                        if( c == 27 || c == 'q' || c == 'Q' )
                            break;
                    }
                }
                fclose(f);
            }
        }
    }*/
    cvDestroyWindow( "Motion" );
    cvDestroyWindow("result");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void detectAndDraw( Mat& img, IplImage* image,
                   CascadeClassifier& cascade, CascadeClassifier& nestedCascade,
                   double scale, IplImage* motion)
{
    int i = 0;
    double t = 0;
    vector<Rect> faces;
    const static Scalar colors[] =  { CV_RGB(0,0,255),
        CV_RGB(0,128,255),
        CV_RGB(0,255,255),
        CV_RGB(0,255,0),
        CV_RGB(255,128,0),
        CV_RGB(255,255,0),
        CV_RGB(255,0,0),
        CV_RGB(255,0,255)} ;
    Mat gray, smallImg( cvRound (img.rows/scale), cvRound(img.cols/scale), CV_8UC1 );

    cvtColor( img, gray, CV_BGR2GRAY );



    static vector<Rect> old_faces;
    static int occ = 0;

    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    update_mhi(image, motion, 30);


    t = (double)cvGetTickCount();
    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CV_HAAR_FIND_BIGGEST_OBJECT
        |CV_HAAR_DO_ROUGH_SEARCH
        //|CV_HAAR_SCALE_IMAGE
        ,
        Size(30, 30) );
    t = (double)cvGetTickCount() - t;
    printf( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );

    if (faces.empty())
    {
      if (occ++ == 20)
      {
        occ = 0;
        old_faces.clear();
      }
      else
        faces = old_faces;
    }
    else
      old_faces = faces;

	if (faces.size() == 0)
	{
		std::stringstream messagecpp;
		std::string str_noob;
		
		messagecpp << "up:1:" << 0 << ":" << 0;
		str_noob = messagecpp.str();
		const char *message_to_send = str_noob.c_str();
		
		// server send and rcv!!
		
		send(conn, message_to_send, strlen(message_to_send), MSG_OOB);
		
		memset(&message, 0, MSG_SIZE);
		
		size_recv = recv(conn, message, MSG_SIZE, MSG_PEEK);
		if ( size_recv == -1)
		{
			perror("didn't received message");
			close(sd);
			return;
		}
		else if ( size_recv == 0)
		{
			perror("the peer closed the connexion");
			close(sd);
			return;
		}
		else {
			std::cout << message << std::endl;
		}
	}
	else
    {
		int cpt_loop = 0;
		for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
		{
			Mat smallImgROI;
			vector<Rect> nestedObjects;
			Point center;
			Scalar color = colors[i%8];
			int radius;
			
			std::stringstream messagecpp;
			std::string str_noob;
			cpt_loop++;
			messagecpp << "down:" << cpt_loop << ":" << r->x << ":" << r->y;
			str_noob = messagecpp.str();
			const char *message_to_send = str_noob.c_str();
			
			// server send and rcv!!
			
			send(conn, message_to_send, strlen(message_to_send), MSG_OOB);
			
			
			memset(&message, 0, MSG_SIZE);
			
			size_recv = recv(conn, message, MSG_SIZE, MSG_PEEK);
			if ( size_recv == -1)
			{
				perror("didn't received message");
				close(sd);
				return;
			}
			else if ( size_recv == 0)
			{
				perror("the peer closed the connexion");
				close(sd);
				return;
			}
			else {
				std::cout << message << std::endl;
			}
			
			// fin de la partie server.
			
			center.x = cvRound((r->x + r->width*0.5)*scale);
			center.y = cvRound((r->y + r->height*0.5)*scale);
			radius = cvRound((r->width + r->height)*0.25*scale);
			
			//std::cout << "radius = " << radius << std::endl;
			if (radius > 25)
				continue;
			
			
			circle( img, center, radius, color, 3, 8, 0 );
			if( nestedCascade.empty() )
				continue;
			smallImgROI = smallImg(*r);
			nestedCascade.detectMultiScale( smallImgROI, nestedObjects,
										   1.1, 2, 0
										   //|CV_HAAR_FIND_BIGGEST_OBJECT
										   //|CV_HAAR_DO_ROUGH_SEARCH
										   //|CV_HAAR_DO_CANNY_PRUNING
										   |CV_HAAR_SCALE_IMAGE
										   ,
										   Size(30, 30) );
			for( vector<Rect>::const_iterator nr = nestedObjects.begin(); nr != nestedObjects.end(); nr++ )
			{
				center.x = cvRound((r->x + nr->x + nr->width*0.5)*scale);
				center.y = cvRound((r->y + nr->y + nr->height*0.5)*scale);
				radius = cvRound((nr->width + nr->height)*0.25*scale);
				circle( img, center, radius, color, 3, 8, 0 );
			}
		}	
	}


    cv::imshow( "result", img );
    cvShowImage( "Motion", motion );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
