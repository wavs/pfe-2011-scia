#include "renderer_3D.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Renderer3D::Renderer3D()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Renderer3D::~Renderer3D()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer3D::PreRender()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer3D::PostRender()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer3D::DrawSphere(const Vector3& parPosition, float parRadius, const Color& parColor)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer3D::DrawCube(const Vector3& parPosition, float parSize, const Color& parColor)
{
  float halfSize = parSize / 2.0f;
  Vector3 min(parPosition - Vector3(halfSize, halfSize, halfSize));
  VertexWriter<Vertex::TT2F_V3F>& vertexWriter = GetVertexWriter<Vertex::TT2F_V3F>(0, 8, 12);

  Vertex::TT2F_V3F* vertex = NULL;
  vertex = &vertexWriter.GetVertex(0);
  vertex->position = min;
  vertex = &vertexWriter.GetVertex(1);
  vertex->position = min + Vector3(0.0f, parSize, 0.0f);
  vertex = &vertexWriter.GetVertex(2);
  vertex->position = min + Vector3(parSize, parSize, 0.0f);
  vertex = &vertexWriter.GetVertex(3);
  vertex->position = min + Vector3(parSize, 0.0f, 0.0f);
  vertex = &vertexWriter.GetVertex(4);
  vertex->position = min + Vector3(0.0f, 0.0f, parSize);
  vertex = &vertexWriter.GetVertex(5);
  vertex->position = min + Vector3(0.0f, parSize, parSize);
  vertex = &vertexWriter.GetVertex(6);
  vertex->position = min + Vector3(parSize, parSize, parSize);
  vertex = &vertexWriter.GetVertex(7);
  vertex->position = min + Vector3(parSize, 0.0f, parSize);

  vertexWriter.AddTriangle(0, 2, 1);
  vertexWriter.AddTriangle(0, 3, 2);
  vertexWriter.AddTriangle(4, 5, 6);
  vertexWriter.AddTriangle(4, 6, 7);
  vertexWriter.AddTriangle(0, 4, 7);
  vertexWriter.AddTriangle(0, 7, 3);
  vertexWriter.AddTriangle(0, 1, 5);
  vertexWriter.AddTriangle(0, 5, 4);
  vertexWriter.AddTriangle(2, 3, 7);
  vertexWriter.AddTriangle(2, 7, 6);
  vertexWriter.AddTriangle(2, 6, 5);
  vertexWriter.AddTriangle(2, 5, 1);

  vertexWriter.Finish();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer3D::DrawPyramid(const Vector3& parPosition, float parSize, const Color& parColor)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer3D::Draw()
{
  Renderer::Draw();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
