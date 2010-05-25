////////////////////////////////////////////////////////////////////////////////
// Filename  : renderer.hh
// Authors   : Creteur Clement
// Last edit : 11/01/10 - 23h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_RENDERER_HH
#define GFX_RENDERER_HH

#include "triangle_bag.hh"
#include "material.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Renderer
{
  public:
    Renderer();
    virtual ~Renderer();

    virtual void PreRender() = 0;
    virtual void PostRender() = 0;

    virtual void Draw();
    void Clear();
    void Flush();

    template<class T>
    VertexWriter<T>& GetVertexWriter(unsigned parMaterialId, unsigned parVertexCount, unsigned parTriangleCount);

  protected:
    TriangleBag* MTriangleBags[MaterialEnum::COUNT];
    TriangleBag* MTriangleBagsAlpha[MaterialEnum::COUNT];
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "renderer.hxx"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
