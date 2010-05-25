////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_parent_loader.hh
// Authors   : Creteur Clement
// Last edit : 21/05/11 - 19h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_PARENT_LOADER_HH
#define UI_PARENT_LOADER_HH

#include "ui_loader.hh"
#include <vector>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIParentLoader : public UILoader
{
  public:
    UIParentLoader(const std::string& parName);
    ~UIParentLoader();

  protected:
    void ExtractChilds(XmlNode* parNode,
                       std::vector<UIComponent*>& parChilds,
                       bool parExtractNode = true);
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
