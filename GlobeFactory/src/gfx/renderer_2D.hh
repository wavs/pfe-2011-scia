////////////////////////////////////////////////////////////////////////////////
// Filename  : renderer_2D.hh
// Authors   : Creteur Clement
// Last edit : 11/01/10 - 23h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_RENDERER_2D_HH
#define GFX_RENDERER_2D_HH

#include "renderer.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Renderer2D : public Renderer
{
  public:
    Renderer2D();
    ~Renderer2D();

    void PreRender();
    void PostRender();
    void Draw();

    void DrawLine(const Vector2f& parStart, const Vector2f& parEnd, const Color& parColor);
    void DrawQuad(const BB2f& parBB, const Color& parColor);
    void DrawQuad(const BB2f& parBB, unsigned parMaterialId);
    void DrawQuad(const BB2f& parBB, unsigned parMaterialId, const Color& parColor);

    double NextLayer();

  private:
    struct Line
    {
      Line(const Vector2f& parStart, const Vector2f& parEnd, const Color& parColor, double parLayer)
        : start(parStart),
          end(parEnd),
          color(parColor),
          layer(parLayer)
      {
      }

      Vector2f start;
      Vector2f end;
      Color    color;
      double   layer;
    };

    void DrawLines();

    std::vector<Line> MLines;
    double            MLayer;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
