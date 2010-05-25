////////////////////////////////////////////////////////////////////////////////
// Filename  : renderer_3D.hh
// Authors   : Creteur Clement
// Last edit : 11/01/10 - 23h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_RENDERER_3D_HH
#define GFX_RENDERER_3D_HH

#include "renderer.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Renderer3D : public Renderer
{
  public:
    Renderer3D();
    ~Renderer3D();

    void PreRender();
    void PostRender();
    void Draw();

    void DrawSphere(const Vector3& parPosition, float parRadius, const Color& parColor = BaseColor::RED);
    void DrawCube(const Vector3& parPosition, float parSize, const Color& parColor = BaseColor::GREEN);
    void DrawPyramid(const Vector3& parPosition, float parSize, const Color& parColor = BaseColor::BLUE);

  private:
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
