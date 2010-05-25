#include "renderer_2D.hh"
#include "gfx_engine.hh"
#include "window_opengl_sdl.hh"
#include <gl/glu.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const double INITIAL_LAYER = -1;
const double STEP_LAYER    = 0.000001;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Renderer2D::Renderer2D()
  : MLayer(INITIAL_LAYER)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Renderer2D::~Renderer2D()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::PreRender()
{
  glClear(GL_DEPTH_BUFFER_BIT);

  int vPort[4];
  glGetIntegerv(GL_VIEWPORT, vPort);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, vPort[2], 0, vPort[3], -1, 1);

  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);

  MLayer = INITIAL_LAYER;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::PostRender()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

double Renderer2D::NextLayer()
{
  if (MLayer > 0.9)
  {
    LOG_WARNING("Renderer2D", "Too much layer used for the renderer2D.");
    MLayer = INITIAL_LAYER;
  }

  MLayer += STEP_LAYER;

  return MLayer;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::DrawQuad(const BB2f& parBB, unsigned parMaterialId, const Color& parColor)
{
  double layer = NextLayer();

  VertexWriter<Vertex::TT2F_C4UB_V3F>& vertexWriter = GetVertexWriter<Vertex::TT2F_C4UB_V3F>(parMaterialId, 4, 2);

  Vertex::TT2F_C4UB_V3F& v0 = vertexWriter.GetVertex(0);
  Vertex::TT2F_C4UB_V3F& v1 = vertexWriter.GetVertex(1);
  Vertex::TT2F_C4UB_V3F& v2 = vertexWriter.GetVertex(2);
  Vertex::TT2F_C4UB_V3F& v3 = vertexWriter.GetVertex(3);

  const Vector2f& min = parBB.Min();
  const Vector2f& max = parBB.Max();

  v0.position = Vector3(min.x(), min.y(), layer);
  v1.position = Vector3(min.x(), max.y(), layer);
  v2.position = Vector3(max.x(), max.y(), layer);
  v3.position = Vector3(max.x(), min.y(), layer);

  v0.color4Ub[0] = v1.color4Ub[0] = v2.color4Ub[0] = v3.color4Ub[0] = static_cast<unsigned char>(255 * parColor.r());
  v0.color4Ub[1] = v1.color4Ub[1] = v2.color4Ub[1] = v3.color4Ub[1] = static_cast<unsigned char>(255 * parColor.g());
  v0.color4Ub[2] = v1.color4Ub[2] = v2.color4Ub[2] = v3.color4Ub[2] = static_cast<unsigned char>(255 * parColor.b());
  v0.color4Ub[3] = v1.color4Ub[3] = v2.color4Ub[3] = v3.color4Ub[3] = static_cast<unsigned char>(255 * parColor.a());

  v0.texCoord = Vector2f(0.f, 0.f);
  v1.texCoord = Vector2f(0.f, 1.f);
  v2.texCoord = Vector2f(1.f, 1.f);
  v3.texCoord = Vector2f(1.f, 0.f);

  vertexWriter.AddTriangle(0, 1, 2);
  vertexWriter.AddTriangle(0, 2, 3);

  vertexWriter.Finish();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::DrawQuad(const BB2f& parBB, const Color& parColor)
{
  double layer = NextLayer();

  VertexWriter<Vertex::TC4UB_V3F>& vertexWriter = GetVertexWriter<Vertex::TC4UB_V3F>(MaterialMng::NONE_ID, 4, 2);

  Vertex::TC4UB_V3F& v0 = vertexWriter.GetVertex(0);
  Vertex::TC4UB_V3F& v1 = vertexWriter.GetVertex(1);
  Vertex::TC4UB_V3F& v2 = vertexWriter.GetVertex(2);
  Vertex::TC4UB_V3F& v3 = vertexWriter.GetVertex(3);

  const Vector2f& min = parBB.Min();
  const Vector2f& max = parBB.Max();

  v0.position = Vector3(min.x(), min.y(), layer);
  v1.position = Vector3(min.x(), max.y(), layer);
  v2.position = Vector3(max.x(), max.y(), layer);
  v3.position = Vector3(max.x(), min.y(), layer);

  v0.color4Ub[0] = v1.color4Ub[0] = v2.color4Ub[0] = v3.color4Ub[0] = static_cast<unsigned char>(255 * parColor.r());
  v0.color4Ub[1] = v1.color4Ub[1] = v2.color4Ub[1] = v3.color4Ub[1] = static_cast<unsigned char>(255 * parColor.g());
  v0.color4Ub[2] = v1.color4Ub[2] = v2.color4Ub[2] = v3.color4Ub[2] = static_cast<unsigned char>(255 * parColor.b());
  v0.color4Ub[3] = v1.color4Ub[3] = v2.color4Ub[3] = v3.color4Ub[3] = static_cast<unsigned char>(255 * parColor.a());

  vertexWriter.AddTriangle(0, 1, 2);
  vertexWriter.AddTriangle(0, 2, 3);

  vertexWriter.Finish();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::DrawQuad(const BB2f& parBB, unsigned parMaterialId)
{
  double layer = NextLayer();

  VertexWriter<Vertex::TT2F_V3F>& vertexWriter = GetVertexWriter<Vertex::TT2F_V3F>(parMaterialId, 4, 2);

  Vertex::TT2F_V3F& v0 = vertexWriter.GetVertex(0);
  Vertex::TT2F_V3F& v1 = vertexWriter.GetVertex(1);
  Vertex::TT2F_V3F& v2 = vertexWriter.GetVertex(2);
  Vertex::TT2F_V3F& v3 = vertexWriter.GetVertex(3);

  const Vector2f& min = parBB.Min();
  const Vector2f& max = parBB.Max();

  v0.position = Vector3(min.x(), min.y(), layer);
  v1.position = Vector3(min.x(), max.y(), layer);
  v2.position = Vector3(max.x(), max.y(), layer);
  v3.position = Vector3(max.x(), min.y(), layer);

  v0.texCoord = Vector2f(0.f, 0.f);
  v1.texCoord = Vector2f(0.f, 1.f);
  v2.texCoord = Vector2f(1.f, 1.f);
  v3.texCoord = Vector2f(1.f, 0.f);

  vertexWriter.AddTriangle(0, 1, 2);
  vertexWriter.AddTriangle(0, 2, 3);

  vertexWriter.Finish();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::DrawLine(const Vector2f& parStart, const Vector2f& parEnd, const Color& parColor)
{
  MLines.push_back(Line(parStart, parEnd, parColor, NextLayer()));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::Draw()
{
  Renderer::Draw();
  DrawLines();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer2D::DrawLines()
{
  foreach(line, MLines)
  {
    Line& curLine = *line;
    glColor4f(curLine.color.r(), curLine.color.g(), curLine.color.b(), curLine.color.a());
    glBegin(GL_LINES);
    {
      glVertex3f(curLine.start.x(), curLine.start.y(), curLine.layer);
      glVertex3f(curLine.end.x(), curLine.end.y(), curLine.layer);
    }
    glEnd();
  }

  MLines.clear();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
