////////////////////////////////////////////////////////////////////////////////
// Filename  : input_mng.hh
// Authors   : Creteur Clement
// Last edit : 01/11/09 - 19h14
// Comment   : This singleton manages the user input events. It reads the
//             keystates (etc...) and sends the events to the userInput
//             Listeners according to the priorities (0 = lower priority).
////////////////////////////////////////////////////////////////////////////////
#ifndef INPUT_MNG_HH
#define INPUT_MNG_HH

#include <vector>
#include <string>
#include "singleton.hh"
#include "user_input.hh"
#include "updatable.hh"
#include "vector.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class InputListener;
class Timer;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class InputMng : public Singleton<InputMng>, public Updatable
{
  friend class Singleton<InputMng>;

  public:
    void Register(InputListener* parClient);
    void Unregister(InputListener* parClient);
    void Update();

    inline const Vector2f& GetMousePosition() const {return MMousePosition;}

  private:
    InputMng();
    ~InputMng();

    MouseEvent::Type SDLToEvt(int parButton);

    const float                 MDClickDelay;
    Timer*                      MTimer;
    std::vector<InputListener*> MLayers;
    bool                        MShiftState;
    bool                        MControlState;
    bool                        MAltState;
    SDL_Event                   MSDLEvent;
    MouseEvent::Type            MLastButton;
    float                       MLastButtonTime;
    Vector2f                    MMousePosition;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
