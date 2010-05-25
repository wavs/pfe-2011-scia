#include "combo_box_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComboBoxLoader::UIComboBoxLoader()
  : UILoader("combo_box")
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComboBoxLoader::~UIComboBoxLoader()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComboBox* UIComboBoxLoader::LoadComponent(XmlNode* parNode)
{
  Vector2f pos, sz;

  if (!ExtractBase(parNode, pos, sz))
    return NULL;

  bool state = false;
  if (parNode->GetAttribute("state", state))
    return new UIComboBox(pos, sz, state);
  else
    return new UIComboBox(pos, sz);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
