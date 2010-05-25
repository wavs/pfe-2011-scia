////////////////////////////////////////////////////////////////////////////////
// Filename  : button_loader.hh
// Authors   : Creteur Clement
// Last edit : 21/05/11 - 19h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_BUTTON_LOADER_HH
#define UI_BUTTON_LOADER_HH

#include "../../useful/all.hh"
#include "../ui_button.hh"
#include "ui_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIButtonLoader : public UILoader
{
  public:
    UIButtonLoader();
    ~UIButtonLoader();

    UIButton* LoadComponent(XmlNode* parNode);
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
