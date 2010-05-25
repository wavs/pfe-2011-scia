////////////////////////////////////////////////////////////////////////////////
// Filename  : window_loader.hh
// Authors   : Creteur Clement
// Last edit : 24/05/11 - 19h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_WINDOW_LOADER_HH
#define UI_WINDOW_LOADER_HH

#include "../../useful/all.hh"
#include "../ui_window.hh"
#include "ui_parent_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIWindowLoader : public UIParentLoader
{
  public:
    UIWindowLoader();
    ~UIWindowLoader();

    UIWindow* LoadComponent(XmlNode* parNode);
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
