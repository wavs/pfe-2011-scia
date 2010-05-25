#include "ui_window.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/renderer_2D.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIWindow::UIWindow(const Vector2f& parPosition, const Vector2f& parSize, float parBarSize)
  : UIContainer(parPosition, parSize),
    MBarSize(parBarSize),
    MIsSelected(false)
{
  LOG_ASSERT(parBarSize < parSize.y());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIWindow::~UIWindow()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIWindow* UIWindow::Clone() const
{
  UIWindow* wind = new UIWindow(MPosition, MSize, MBarSize);

  const_foreach(child, MChilds)
    wind->AddComponent((*child)->Clone());

  return wind;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIWindow::Draw(const UIDrawingContext& parContext)
{
  BB2f bbWind(MPosition, MPosition + MSize - Vector2f(0.f, MBarSize));
  BB2f bbBar(MPosition + Vector2f(0.f, MSize.y() - MBarSize), MPosition + MSize);

  GfxEngine::get()->GetPostRender2D()->DrawQuad(bbBar, BaseColor::BLUEVIOLET);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(bbWind, BaseColor::GHOSTWHITE);

  UIContainer::Draw(parContext);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIWindow::OnMouseMove(const Vector2f& parPosition)
{
  if (MIsSelected)
  {
    MPosition += parPosition - MLastMousePosition;
  }
  else
    UIContainer::OnMouseMove(parPosition);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIWindow::OnMouseOn(const Vector2f& parPosition)
{
  UIContainer::OnMouseOn(parPosition);
  MIsSelected = false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIWindow::OnMouseOut()
{
  if (MIsSelected)
  {
    Vector2f lmp = GetAbsPosition() + MLastMousePosition;
    Vector2f mp = InputMng::get()->GetMousePosition();
    Vector2f delta =  mp - lmp;
    MPosition += delta;
  }
  else
    UIContainer::OnMouseOut();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIWindow::OnMouseDown()
{
  if (MLastMousePosition.y() > (MSize.y() - MBarSize))
  {
    MIsSelected = true;
  }
  else
    UIContainer::OnMouseDown();

  LOG_ASSERT(MParent != NULL);
  if (MParent != NULL)
    MParent->PutFront(this);

  return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIWindow::OnMouseUp()
{
  MIsSelected = false;
  UIContainer::OnMouseUp();

  return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
