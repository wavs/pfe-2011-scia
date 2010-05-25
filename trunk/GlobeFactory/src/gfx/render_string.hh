////////////////////////////////////////////////////////////////////////////////
// Filename  : render_string.hh
// Authors   : Creteur Clement
// Last edit : 02/01/10 - 15h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_RENDER_STRING_HH
#define GFX_RENDER_STRING_HH

#include "../useful/all.hh"
#include "font_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace AligmentEnum
{
  enum Vertical
  {
    TOP    = 0,
    CENTER = 1,
    BOTTOM = 2
  };

  enum Horizontal
  {
    LEFT   = 0,
    MIDDLE = 1,
    RIGHT  = 2
  };
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Font;
class Color;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class RenderString
{
  public:
    RenderString(const std::string& parFilename, int FontSize);
    RenderString(Font* parFont);
    ~RenderString();

    void SetFont(const std::string& parFilename, int FontSize);
    void SetFont(Font* parFont);

    void Set(const std::string& parText, int parStyle = FontStyle::NORMAL);

    void SetText(const std::string& parText);
    void SetColor(const Color& parColor);
    void SetStyle(int parStyle);
    void SetAligments(AligmentEnum::Horizontal parHorizontal, AligmentEnum::Vertical parVertical);
    void SetTextSize(float parSize) {MTextSize = parSize;}

    inline const std::string& GetText() const {return MText;}

    void Draw(const Vector2f& parPosition) const;

    inline void EnablePostRender() {MPost = true;}
    inline void EnablePreRender()  {MPost = false;}

  private:
    bool                     MPost;
    Font*                    MFont;
    bool                     MOwnFont;
    AligmentEnum::Horizontal MHorizontalAlign;
    AligmentEnum::Vertical   MVerticalAlign;
    Vector2i                 MTextureSize;
    std::string              MText;
    Color                    MColor;
    int                      MStyle;
    float                    MTextSize;
    unsigned                 MMaterialId;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
