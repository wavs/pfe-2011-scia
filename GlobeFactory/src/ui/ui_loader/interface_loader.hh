////////////////////////////////////////////////////////////////////////////////
// Filename  : interface_loader.hh
// Authors   : Creteur Clement
// Last edit : 21/05/11 - 19h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef INTERFACE_LOADER_HH
#define INTERFACE_LOADER_HH

#include "ui_parent_loader.hh"
#include "../user_interface.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class InterfaceLoader : public UIParentLoader
{
  public:
    InterfaceLoader();
    ~InterfaceLoader();

    UserInterface* LoadComponent(XmlNode* parNode);
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
