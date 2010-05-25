#include "ui_check_box.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/renderer_2D.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UICheckBox::UICheckBox(const Vector2f& parPosition, const Vector2f& parSize, bool parState)
  : UIComponent(parPosition, parSize),
    MState(parState)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UICheckBox::~UICheckBox()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UICheckBox* UICheckBox::Clone() const
{
  UICheckBox* cb = new UICheckBox(MPosition, MSize, MState);
  return cb;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UICheckBox::Draw(const UIDrawingContext& parContext)
{
  BB2f bb(parContext.position + MPosition, parContext.position + MPosition + MSize);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, BaseColor::WHITESMOKE);

  if (MState)
  {
    bb.Min() += Vector2f(2.f, 2.f);
    bb.Max() -= Vector2f(2.f, 2.f);
    GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, BaseColor::BLACK);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UICheckBox::OnMouseDown()
{
  MState = !MState;
  return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
