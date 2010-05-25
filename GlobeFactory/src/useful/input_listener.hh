////////////////////////////////////////////////////////////////////////////////
// Filename  : input_listener.hh
// Authors   : Creteur Clement
// Last edit : 01/11/09 - 19h34
// Comment   : This listener registers itself on creation time. Then, each time
//             the InputManager is updated, it sends the event to the listeners.
//             The virtual methods return true if it did something with the
//             input.
////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_LISTENER_HH
#define INPUT_LISTENER_HH

#include <string>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class KeyboardEvent;
class MouseEvent;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class InputListener
{
  public:
    InputListener(unsigned parPriority, const std::string& parName);
    virtual ~InputListener();

    virtual void OnQuit() {}
    virtual bool OnKeyboardEvent(const KeyboardEvent&) {return false;}
    virtual bool OnMouseEvent(const MouseEvent&) {return false;}

    inline unsigned           GetPriority() const {return MPriority;}
    inline const std::string& GetName()     const {return MName;}


  private:
    unsigned    MPriority;
    std::string MName;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
