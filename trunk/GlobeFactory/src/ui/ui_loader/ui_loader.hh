////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_loader.hh
// Authors   : Creteur Clement
// Last edit : 21/05/11 - 19h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_LOADER_HH
#define UI_LOADER_HH

#include "../../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIComponent;
class UIParentLoader;
class InterfaceLoader;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UILoader
{
  friend class UIParentLoader;
  friend class InterfaceLoader;

  protected:
    UILoader(const std::string& parName);
    virtual ~UILoader();

    virtual UIComponent* LoadComponent(XmlNode* parNode) = 0;

    UILoader* GetLoader(const std::string& parName);
    bool      ExtractBase(XmlNode* parNode, Vector2f& parPos, Vector2f& parSz);

  private:
    std::string MName;
    static std::map<std::string, UILoader*> MLoaders;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
