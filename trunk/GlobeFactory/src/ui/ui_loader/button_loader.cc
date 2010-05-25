#include "button_loader.hh"
#include "../ui_cmd_button.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIButtonLoader::UIButtonLoader()
  : UILoader("button")
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIButtonLoader::~UIButtonLoader()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIButton* UIButtonLoader::LoadComponent(XmlNode* parNode)
{
  Color color;
  Vector2f pos, sz;

  if (!ExtractBase(parNode, pos, sz))
    return NULL;

  std::string mat, matOn, matClick, text, cmd, arg;
  parNode->GetAttribute("material", mat);
  parNode->GetAttribute("material_on", matOn);
  parNode->GetAttribute("material_click", matClick);
  parNode->GetAttribute("text", text);
  parNode->GetAttribute("arg", arg);

  UIButton* butt = NULL;
  if (parNode->GetAttribute("cmd", cmd))
  {
    UICmdButton* cmd_butt = new UICmdButton(pos, sz, mat, matOn, matClick, cmd);
    cmd_butt->SetArg(arg);
    butt = cmd_butt;
  }
  else
    butt = new UIButton(pos, sz, mat, matOn, matClick);

  butt->SetText(text);

  if (XmlHelper::ExtractColor(parNode, color, "color"))
    butt->SetColor(color);
  if (XmlHelper::ExtractColor(parNode, color, "color_on"))
    butt->SetColorOn(color);
  if (XmlHelper::ExtractColor(parNode, color, "color_click"))
    butt->SetColorClick(color);

  if (XmlHelper::ExtractColor(parNode, color, "text_color"))
    butt->SetTextColor(color);
  if (XmlHelper::ExtractColor(parNode, color, "text_color_on"))
    butt->SetTextColorOn(color);
  if (XmlHelper::ExtractColor(parNode, color, "text_color_click"))
    butt->SetTextColorClick(color);

  return butt;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
