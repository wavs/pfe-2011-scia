////////////////////////////////////////////////////////////////////////////////
// Filename  : font_mng.hh
// Authors   : Creteur Clement
// Last edit : 02/01/10 - 15h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_FONT_MNG_HH
#define GFX_FONT_MNG_HH

#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace FontStyle
{
  extern const int NORMAL;
  extern const int BOLD;
  extern const int ITALIC;
  extern const int UNDERLINE;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

typedef struct _TTF_Font TTF_Font;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Font : public ManualRefCounter
{
  friend class FontMng;

  public:
    unsigned NewStrTexture(const std::string& parText, Vector2i& parSize, int parStyle = FontStyle::NORMAL);
    void DeleteStrTexture(unsigned parId);

  private:
    Font(const std::string& parFilename, int parFontSize);
    Font(const Font&);
    ~Font();

    std::string MFilename;
    int         MFontSize;
    TTF_Font*   MFont;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class FontMng : public Singleton<FontMng>
{
  friend class Singleton<FontMng>;

  public:
    Font* LoadFont(const std::string& parFilename, int parFontSize);
    void  UnloadFont(const Font* parFont);

  private:
    FontMng();
    FontMng(const FontMng&);
    ~FontMng();

    std::list<Font*> MFonts;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
