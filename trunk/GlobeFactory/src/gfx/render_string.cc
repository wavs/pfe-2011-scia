#include "render_string.hh"
#include "font_mng.hh"

#include <gl/glu.h>
#include "gfx_engine.hh"
#include "renderer_2d.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

RenderString::RenderString(const std::string& parFilename, int FontSize)
  : MPost(true),
    MFont(NULL),
    MOwnFont(false),
    MHorizontalAlign(AligmentEnum::RIGHT),
    MVerticalAlign(AligmentEnum::TOP),
    MStyle(FontStyle::NORMAL),
    MTextSize(32.0f),
    MMaterialId(0)
{
  SetFont(parFilename, FontSize);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

RenderString::RenderString(Font* parFont)
  : MPost(true),
    MFont(NULL),
    MOwnFont(false),
    MHorizontalAlign(AligmentEnum::RIGHT),
    MVerticalAlign(AligmentEnum::TOP),
    MStyle(FontStyle::NORMAL),
    MTextSize(32.0f),
    MMaterialId(0)
{
  SetFont(parFont);
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

RenderString::~RenderString()
{
  LOG_ASSERT(MFont != NULL);

  if (MMaterialId != 0)
    MaterialMng::get()->UnloadMaterial(MMaterialId);

  if (MOwnFont)
    FontMng::get()->UnloadFont(MFont);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::SetFont(const std::string& parFilename, int FontSize)
{
  if (MOwnFont)
    FontMng::get()->UnloadFont(MFont);

  MFont = FontMng::get()->LoadFont(parFilename, FontSize);
  MOwnFont = true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::SetFont(Font* parFont)
{
  LOG_ASSERT(MFont != NULL);
  LOG_ASSERT(parFont != NULL);

  if (MOwnFont)
    FontMng::get()->UnloadFont(MFont);

  MFont = parFont;
  MOwnFont = false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::Set(const std::string& parText, int parStyle)
{
  MStyle = parStyle;
  MText = parText;

  if (MMaterialId != 0)
    MaterialMng::get()->UnloadMaterial(MMaterialId);

  if (parText.empty())
    MMaterialId = 0;
  else
    MMaterialId = MaterialMng::get()->LoadTextMaterial(MFont, MText, MTextureSize, MStyle);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::SetText(const std::string& parText)
{
  Set(parText, MStyle);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::SetColor(const Color& parColor)
{
  MColor = parColor;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::SetStyle(int parStyle)
{
  MStyle = parStyle;
  Set(MText, MStyle);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::SetAligments(AligmentEnum::Horizontal parHorizontal, AligmentEnum::Vertical parVertical)
{
  MHorizontalAlign = parHorizontal;
  MVerticalAlign   = parVertical;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void RenderString::Draw(const Vector2f& parPosition) const
{
  if (MMaterialId == 0)
    return;

  LOG_ASSERT(MTextureSize.x() > 0.0f);
  Vector2f size(MTextureSize.x() * MTextSize / MTextureSize.y(), MTextSize);

  BB2f bb;
  bb.Min() = parPosition;

  if (MHorizontalAlign == AligmentEnum::LEFT)
    bb.Min().x() -= size.x();
  else if (MHorizontalAlign == AligmentEnum::MIDDLE)
    bb.Min().x() -= size.x() / 2.0f;

  if (MVerticalAlign == AligmentEnum::BOTTOM)
    bb.Min().y() -= size.y();
  else if (MVerticalAlign == AligmentEnum::CENTER)
    bb.Min().y() -= size.y() / 2.0f;

  bb.Max().Set(bb.Min().x() + size.x(), bb.Min().y() + size.y());

  if (MPost)
    GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MMaterialId, MColor);
  else
    GfxEngine::get()->GetPreRender2D()->DrawQuad(bb, MMaterialId, MColor);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
