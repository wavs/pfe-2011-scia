////////////////////////////////////////////////////////////////////////////////
// Filename  : gfx_engine.hh
// Authors   : Creteur Clement
// Last edit : 26/11/09 - 23h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_ENGINE_HH
#define GFX_ENGINE_HH

#include "../useful/singleton.hh"
#include "../useful/updatable.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class RenderWindow;
class Renderer2D;
class Renderer3D;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class GfxEngine : public Singleton<GfxEngine>, public Updatable
{
  friend class Singleton<GfxEngine>;

  public:
    virtual void Update();

    inline const RenderWindow* GetWindow() const {return MWindow;}

    inline Renderer2D* GetPreRender2D()  {return MPreRender2D;}
    inline Renderer2D* GetPostRender2D() {return MPostRender2D;}
    inline Renderer3D* GetRender3D()     {return MRender3D;}

    void Flush();

  private:
    GfxEngine();
    ~GfxEngine();

    RenderWindow* MWindow;
    Renderer2D*   MPreRender2D;
    Renderer2D*   MPostRender2D;
    Renderer3D*   MRender3D;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
