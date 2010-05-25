#include "ui_button.hh"
#include "ui_container.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/renderer_2D.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIButton::UIButton(const Vector2f& parPosition, const Vector2f& parSize,
                   const std::string& parMat,
                   const std::string& parMatOn,
                   const std::string& parMatClick)
  : UIComponent(parPosition, parSize),
    MColor(BaseColor::WHITE),
    MColorOn(BaseColor::WHITE),
    MColorClick(BaseColor::WHITE),
    MMat(MaterialMng::NONE_ID),
    MMatOn(MaterialMng::NONE_ID),
    MMatClick(MaterialMng::NONE_ID),
    MText("arial.ttf", 32),
    MDown(false),
    MOn(false)
{
  MTextColor      = BaseColor::BLACK;
  MTextColorOn    = BaseColor::BLACK;
  MTextColorClick = BaseColor::BLACK;

  MText.Set("[NO TEXT]");
  MText.SetColor(MTextColor);
  MText.SetAligments(AligmentEnum::MIDDLE, AligmentEnum::CENTER);

  if (!parMat.empty())
    MMat = MaterialMng::get()->LoadMaterial(parMat);
  if (!parMatOn.empty())
    MMatOn = MaterialMng::get()->LoadMaterial(parMatOn);
  if (!parMatClick.empty())
    MMatClick = MaterialMng::get()->LoadMaterial(parMatClick);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIButton::~UIButton()
{
  if (MMat != MaterialMng::NONE_ID)
    MaterialMng::get()->UnloadMaterial(MMat);
  if (MMatOn != MaterialMng::NONE_ID)
    MaterialMng::get()->UnloadMaterial(MMatOn);
  if (MMatClick != MaterialMng::NONE_ID)
    MaterialMng::get()->UnloadMaterial(MMatClick);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIButton* UIButton::Clone() const
{
  UIButton* button = new UIButton(MPosition, MSize);
  button->MColor = MColor;
  button->MColorOn = MColorOn;
  button->MColorClick = MColorClick;

  MaterialMng::get()->AddUserOnMaterial(MMat);
  MaterialMng::get()->AddUserOnMaterial(MMatOn);
  MaterialMng::get()->AddUserOnMaterial(MMatClick);
  button->MMat = MMat;
  button->MMatOn = MMatOn;
  button->MMatClick = MMatClick;

  button->MText.SetText(MText.GetText());

  return button;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIButton::Draw(const UIDrawingContext& parContext)
{
  BB2f bb(parContext.position + MPosition, parContext.position + MPosition + MSize);

  if (MDown)
  {
    if (MMatClick != MaterialMng::NONE_ID)
      GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MMatClick);
    else
      GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MColorClick);
  }
  else if (MOn)
  {
    if (MMatOn != MaterialMng::NONE_ID)
      GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MMatOn);
    else
      GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MColorOn);
  }
  else
  {
    if (MMat != MaterialMng::NONE_ID)
      GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MMat);
    else
      GfxEngine::get()->GetPostRender2D()->DrawQuad(bb, MColor);
  }

  Vector2f centerPos(MPosition.x() + MSize.x() / 2.0f, MPosition.y() + MSize.y() / 2.0f);
  MText.Draw(centerPos);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIButton::OnMouseMove(const Vector2f& parPosition)
{
  MOn = true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIButton::OnMouseOn(const Vector2f& parPosition)
{
  MText.SetColor(MTextColorOn);

  MDown = false;
  MOn = true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIButton::OnMouseOut()
{
  MText.SetColor(MTextColor);

  MDown = false;
  MOn = false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIButton::OnEnter()
{
  MDown = false;
  Action();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIButton::OnMouseDown()
{
  MText.SetColor(MTextColorClick);

  MDown = true;

  if (MParent != NULL)
    MParent->SetFocus(this);

  return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIButton::OnMouseUp()
{
  MText.SetColor(MTextColorOn);

  if (MDown)
    Action();

  MDown = false;
  return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
