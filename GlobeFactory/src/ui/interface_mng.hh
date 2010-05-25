////////////////////////////////////////////////////////////////////////////////
// Filename  : interface_mng.hh
// Authors   : Creteur Clement
// Last edit : 05/02/10 - 17h26
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_INTERFACE_MNG_HH
#define UI_INTERFACE_MNG_HH

#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UserInterface;
class UIComponent;
class InterfaceLoader;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class InterfaceMng : public Singleton<InterfaceMng>,
                     public InputListener,
                     public Updatable
{
  friend class Singleton<InterfaceMng>;
  public:
    void     Update();

    unsigned CreateInterface();
    unsigned LoadFromXML(const std::string& parFilename);
    void     DeleteInterface(unsigned parId);


    void     ToggleVisibility(unsigned parId);
    void     SetVisibility(unsigned parId, bool parVisible);
    void     AddComponent(unsigned parId, UIComponent* parCompo);

    bool OnKeyboardEvent(const KeyboardEvent& parEvent);
    bool OnMouseEvent(const MouseEvent& parEvent);

  private:
    InterfaceMng();
    ~InterfaceMng();

    std::vector<UserInterface*> MInterfaces;
    InterfaceLoader*            MInterfaceLoader;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
