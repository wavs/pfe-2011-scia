////////////////////////////////////////////////////////////////////////////////
// Filename  : window_opengl_sdl.hh
// Authors   : Creteur Clement
// Last edit : 23/01/10 - 17h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_WINDOW_OPENGL_SDL_HH
#define GFX_WINDOW_OPENGL_SDL_HH

#include "render_window.hh"
#include "../useful/vector.hh"
#include "../useful/color.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class WindowOpenglSDL : public RenderWindow
{
  public:
    WindowOpenglSDL();
    ~WindowOpenglSDL();

    void PreRender();
    void PostRender();

  private:
    void InitializeFromFile(const std::string& parFilename);

    Color MClearColor;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
