////////////////////////////////////////////////////////////////////////////////
// Filename  : render_window.hh
// Authors   : Creteur Clement
// Last edit : 06/03/10 - 17h06
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef RENDER_WINDOW_HH
#define RENDER_WINDOW_HH

#include "../useful/vector.hh"
#include "../useful/color.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class RenderWindow
{
  public:
    RenderWindow()
    : MWindowName("- No name defined -"),
      MResolution(800, 600),
      MIsFullscreen(false)
    {
    }

    virtual ~RenderWindow() {}

    virtual void PreRender()  = 0;
    virtual void PostRender() = 0;

    inline const Vector2i& GetResolution() const {return MResolution;}
    inline bool            IsFullscreen()  const {return MIsFullscreen;}

  protected:
    std::string MWindowName;
    Vector2i    MResolution;
    bool        MIsFullscreen;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
