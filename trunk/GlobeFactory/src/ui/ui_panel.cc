#include "ui_panel.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/renderer_2D.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIPanel::UIPanel(const Vector2f& parPosition, const Vector2f& parSize)
  : UIContainer(parPosition, parSize),
    MMouseOn(false)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIPanel::~UIPanel()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIPanel* UIPanel::Clone() const
{
  UIPanel* uip = new UIPanel(MPosition, MSize);

  const_foreach(child, MChilds)
    uip->MChilds.push_back((*child)->Clone());

  uip->MColor   = MColor;
  uip->MMouseOn = MMouseOn;

  return uip;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIPanel::Draw(const UIDrawingContext& parContext)
{
  BB2f bb(MPosition, MPosition + MSize);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MMouseOn ? BaseColor::WHITE : MColor);

  UIContainer::Draw(parContext);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIPanel::OnMouseMove(const Vector2f& parPosition)
{
  MMouseOn = true;
  UIContainer::OnMouseMove(parPosition);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIPanel::OnMouseOn(const Vector2f& parPosition)
{
  MMouseOn = true;
  UIContainer::OnMouseOn(parPosition);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIPanel::OnMouseOut()
{
  MMouseOn = false;
  UIContainer::OnMouseOut();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIPanel::OnMouseDown()
{
  if (UIContainer::OnMouseDown())
    return true;

  if (MColor.a() == 0.0f)
    return false;
  else
    return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIPanel::OnMouseUp()
{
  if (UIContainer::OnMouseUp())
    return true;

  if (MColor.a() == 0.0f)
    return false;
  else
    return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
