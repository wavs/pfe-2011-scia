#include "font_mng.hh"
#include "texture_loader.hh"
#include "../useful/all.hh"

#include <GL/glu.h>
#include <GL/gl.h>
#include <SDL/SDL_ttf.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace FontStyle
{
  const int NORMAL = TTF_STYLE_NORMAL;
  const int BOLD = TTF_STYLE_BOLD;
  const int ITALIC = TTF_STYLE_ITALIC;
  const int UNDERLINE = TTF_STYLE_UNDERLINE;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Font::Font(const std::string& parFilename, int parFontSize)
  : MFilename(parFilename),
    MFontSize(parFontSize)
{
  const std::string fullFilename = "font/" + parFilename;
  MFont = TTF_OpenFont(fullFilename.c_str(), parFontSize);
  if (MFont == NULL)
    LOG_ERROR("Font     ", "Try to load a bad font file : " + parFilename);
  else
    LOG_RESUME("Font    ", "New Font loaded : " + parFilename + " with size of "
                                              + misc::ToString(parFontSize));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Font::Font(const Font&)
{
  LOG_ASSERT(false);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Font::~Font()
{
  TTF_CloseFont(MFont);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned Font::NewStrTexture(const std::string& parText, Vector2i& parSize, int parStyle)
{
  SDL_Color color =
  {
    255,
    255,
    255,
    0x00
  };

  TTF_SetFontStyle(MFont, parStyle);
  SDL_Surface* surface = TTF_RenderText_Blended(MFont, parText.c_str(), color);
  LOG_ASSERT(surface != NULL);
  unsigned id = TextureLoader::SDLToGL(surface, parSize);
  LOG_ASSERT(id != 0);
  SDL_FreeSurface(surface);

  return id;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Font::DeleteStrTexture(unsigned parId)
{
  glDeleteTextures(1, &parId);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

FontMng::FontMng()
{
  if (TTF_Init() == -1)
    LOG_ERROR("FontMng", "Unable to load SDL_TTF.");
  else
    LOG_RESUME("FontMng", "FontMng Initialized");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

FontMng::FontMng(const FontMng&)
{
  LOG_ASSERT(false);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

FontMng::~FontMng()
{
  TTF_Quit();
  LOG_ASSERT(MFonts.empty());

  foreach(it, MFonts)
    delete *it;

  LOG_RESUME("FontMng", "FontMng Killed.");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Font* FontMng::LoadFont(const std::string& parFilename, int parFontSize)
{
  foreach(it, MFonts)
    if (((*it)->MFilename == parFilename) && ((*it)->MFontSize == parFontSize))
    {
      (*it)->IncRefCount();
      return *it;
    }

  Font* newFont = new Font(parFilename, parFontSize);
  MFonts.push_back(newFont);
  return newFont;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void FontMng::UnloadFont(const Font* parFont)
{
  LOG_ASSERT(misc::find((Font*)parFont, MFonts));

  foreach(it, MFonts)
    if ((*it) == parFont)
    {
      (*it)->DecRefCount();
      if ((*it)->GetRefCount() == 0)
      {
        delete *it;
        MFonts.erase(it);
        return;
      }
    }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
