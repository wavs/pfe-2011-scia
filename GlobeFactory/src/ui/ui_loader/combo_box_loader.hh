////////////////////////////////////////////////////////////////////////////////
// Filename  : combo_box_loader.hh
// Authors   : Creteur Clement
// Last edit : 25/05/11 - 19h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_COMBO_BOX_LOADER_HH
#define UI_COMBO_BOX_LOADER_HH

#include "../../useful/all.hh"
#include "../ui_combo_box.hh"
#include "ui_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIComboBoxLoader : public UILoader
{
  public:
    UIComboBoxLoader();
    ~UIComboBoxLoader();

    UIComboBox* LoadComponent(XmlNode* parNode);
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
