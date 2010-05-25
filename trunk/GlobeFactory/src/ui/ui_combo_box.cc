#include "ui_combo_box.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/renderer_2D.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComboBox::UIComboBox(const Vector2f& parPosition, const Vector2f& parSize, bool parState)
  : UIComponent(parPosition, parSize),
    MState(parState)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComboBox::~UIComboBox()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComboBox* UIComboBox::Clone() const
{
  return new UIComboBox(MPosition, MSize, MState);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIComboBox::Draw(const UIDrawingContext& parContext)
{
  BB2f bb(parContext.position + MPosition, parContext.position + MPosition + MSize);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, BaseColor::ORANGE);

  if (MState)
  {
    bb.Min() += Vector2f(2.f, 2.f);
    bb.Max() -= Vector2f(2.f, 2.f);
    GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, BaseColor::ORANGERED);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIComboBox::OnMouseDown()
{
  MState = !MState;
  return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
