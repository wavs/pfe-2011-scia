#include "texture_loader.hh"
#include "../useful/all.hh"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/glu.h>
#include <GL/gl.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TextureLoader::TextureLoader()
  : MFilename(),
    MSize(0, 0),
    MGLId(0),
    MHasAlpha(false),
    MLoaded(false)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TextureLoader::TextureLoader(const std::string parFilename)
  : MFilename(),
    MSize(0, 0),
    MGLId(0),
    MHasAlpha(false),
    MLoaded(false)
{
  Reload(parFilename);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TextureLoader::~TextureLoader()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void TextureLoader::Reload(const std::string parFilename)
{
  LOG_ASSERT(!parFilename.empty());
  LOG_ASSERT(parFilename != MFilename);

  MFilename = parFilename;
  MGLId = LoadTexture(std::string("texture/") + parFilename, MSize, MHasAlpha);

  if (MGLId ==  0)
  {
    MLoaded = false;
    MHasAlpha = false;
    MSize.Set(0, 0);
    LOG_WARNING("TextureLoader", "Unable to load the texture " + parFilename);
  }
  else
    MLoaded = true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned TextureLoader::LoadTexture(const std::string& filename, Vector2i& parSize, bool& parHasAlpha) const
{
  SDL_Surface* surface = IMG_Load(filename.c_str());
  if (surface == NULL)
  {
    return 0;
  }
  parHasAlpha = false;

  unsigned glID = SDLToGL(surface, parSize);
  SDL_FreeSurface(surface);

  return glID;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned TextureLoader::SDLToGL(SDL_Surface* parSurface, Vector2i& parSize)
{
  parSize.Set(parSurface->w, parSurface->h);

  SDL_PixelFormat format = *(parSurface->format);
  format.BitsPerPixel    = 32;
  format.BytesPerPixel   = 4;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  format.Rmask = 0xff000000;
  format.Gmask = 0x00ff0000;
  format.Bmask = 0x0000ff00;
  format.Amask = 0x000000ff;
#else
  format.Rmask = 0x000000ff;
  format.Gmask = 0x0000ff00;
  format.Bmask = 0x00ff0000;
  format.Amask = 0xff000000;
#endif

  SDL_Surface* glSurface = SDL_ConvertSurface(parSurface, &format, SDL_SWSURFACE);
  SDL_Surface* glFlipedSurface = FlipSurface(glSurface);
  SDL_FreeSurface(glSurface);

  GLuint glID;
  glGenTextures(1, &glID);
  glBindTexture(GL_TEXTURE_2D, glID);

  gluBuild2DMipmaps(GL_TEXTURE_2D, 4,
                    glFlipedSurface->w, glFlipedSurface->h,
                    GL_RGBA, GL_UNSIGNED_BYTE, glFlipedSurface->pixels);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  SDL_FreeSurface(glFlipedSurface);

  return glID;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SDL_Surface* TextureLoader::FlipSurface(SDL_Surface* surface)
{
  SDL_Surface* fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                surface->w,
                                surface->h,
                                surface->format->BitsPerPixel,
                                surface->format->Rmask,
                                surface->format->Gmask,
                                surface->format->Bmask,
                                surface->format->Amask);

  SDL_LockSurface(surface);
  SDL_LockSurface(fliped_surface);

  int pitch = surface->pitch;
  for (int curLine = 0; curLine < surface->h; ++curLine)
    memcpy(&((unsigned char*)fliped_surface->pixels)[curLine * pitch],
           &((unsigned char*)surface->pixels)[(surface->h - 1 - curLine) * pitch],
           pitch);

  SDL_UnlockSurface(fliped_surface);
  SDL_UnlockSurface(surface);

  return fliped_surface;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
