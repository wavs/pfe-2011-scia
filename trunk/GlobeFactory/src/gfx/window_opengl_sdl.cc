#include "window_opengl_sdl.hh"
#include "../useful/all.hh"
#include "extensions.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

WindowOpenglSDL::WindowOpenglSDL()
{
  InitializeFromFile("window.cfg");

  SDL_Init(SDL_INIT_VIDEO);

  atexit(SDL_Quit);
  SDL_WM_SetCaption(MWindowName.c_str(), NULL);
  SDL_SetVideoMode(MResolution.x(), MResolution.y(), 32, SDL_OPENGL);
  glFlush();
  SDL_GL_SwapBuffers();

  InitExtensions();

  glClearColor(MClearColor.r(), MClearColor.g(), MClearColor.b(), 1.f);

  LOG_RESUME("WindowOglSDL", "Creation of the SDL-GL window with resolution "
             + misc::ToString(MResolution.x()) + "*"
             + misc::ToString(MResolution.y()));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

WindowOpenglSDL::~WindowOpenglSDL()
{
  SDL_Quit();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void WindowOpenglSDL::InitializeFromFile(const std::string& parFilename)
{
  ConfigMng* cfgMng = ConfigMng::get();
  unsigned fileId   = cfgMng->Load(parFilename);

  const std::string* name = cfgMng->GetOptionStr(fileId,   "project_name");
  const int* resolution_x = cfgMng->GetOptionInt(fileId,   "resolution_x");
  const int* resolution_y = cfgMng->GetOptionInt(fileId,   "resolution_y");
  const float* color_r    = cfgMng->GetOptionFloat(fileId, "clear_color_r");
  const float* color_g    = cfgMng->GetOptionFloat(fileId, "clear_color_g");
  const float* color_b    = cfgMng->GetOptionFloat(fileId, "clear_color_b");
  const bool* fullscreen  = cfgMng->GetOptionBool(fileId,  "fullscreen");

  if (name != NULL)
    MWindowName = *name;
  else
    LOG_WARNING("WindowOpenglSDL", "variable 'project_name' not defined in window.cfg");

  if (resolution_x != NULL && resolution_y != NULL)
    MResolution.Set(*resolution_x, *resolution_y);
  else
    LOG_WARNING("WindowOpenglSDL", "variable 'resolution_x/y' not defined in window.cfg");

  if (color_r != NULL && color_g != NULL && color_b)
    MClearColor.Set(*color_r, *color_g, *color_b);

  if (fullscreen != NULL && *fullscreen)
    MIsFullscreen = true;

  cfgMng->Unload(fileId);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void WindowOpenglSDL::PreRender()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void WindowOpenglSDL::PostRender()
{
  glFlush();
  SDL_GL_SwapBuffers();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
