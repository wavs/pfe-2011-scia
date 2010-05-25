////////////////////////////////////////////////////////////////////////////////
// Filename  : user_input.hh
// Authors   : Creteur Clement
// Last edit : 01/11/09 - 19h14
// Comment   : Event that can be interpreted by the input listener. Two kind of
//             event (deriving of BaseEvent) : MouseEvent and KeyboardEvent.
//             They both have informations about CTRL, ALT and Shift State.
////////////////////////////////////////////////////////////////////////////////
#ifndef USER_INPUT_HH
#define USER_INPUT_HH

#include <SDL/SDL.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class BaseEvent
{
  public:
    BaseEvent(bool parUp = false)
      : MIsMasked(true),
        MIsKeyUp(parUp),
        MIsShiftDown(false),
        MIsControlDown(false),
        MIsAltDown(false)
    {}

    ~BaseEvent() {}

    inline void SetKeyStates(bool parShift, bool parControl, bool parAlt)
    {
      MIsShiftDown = parShift;
      MIsControlDown = parControl;
      MIsAltDown = parAlt;
    }

    inline void SetMasked()           {MIsMasked = true;}
    inline bool IsMasked()      const {return MIsMasked;}
    inline bool IsKeyUp()       const {return MIsKeyUp;}
    inline bool IsKeyDown()     const {return !MIsKeyUp;}
    inline bool IsShiftDown()   const {return MIsShiftDown;}
    inline bool IsControlDown() const {return MIsControlDown;}
    inline bool IsAltDown()     const {return MIsAltDown;}

  protected:
    bool MIsMasked;
    bool MIsKeyUp;
    bool MIsShiftDown;
    bool MIsControlDown;
    bool MIsAltDown;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class KeyboardEvent : public BaseEvent
{
  public:
    KeyboardEvent(bool parUp, int parVK, Uint8 parSC, Uint16 parUC)
      : BaseEvent(parUp),
        MVirtualKey(parVK),
        MScanCode(parSC),
        MUniCode(parUC)
    {
    }

    ~KeyboardEvent() {}

    inline int    GetVirtualKey() const {return MVirtualKey;}
    inline Uint8  GetScanCode()   const {return MScanCode;}
    inline Uint16 GetUniCode()    const {return MUniCode;}

  private:
    int    MVirtualKey;
    Uint8  MScanCode;
    Uint16 MUniCode;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class MouseEvent : public BaseEvent
{
  public:
    enum Type
    {
      EVT_CLICK_MOUSE1,
      EVT_CLICK_MOUSE2,
      EVT_CLICK_MOUSE3,
      EVT_DCLICK_MOUSE1,
      EVT_DCLICK_MOUSE2,
      EVT_DCLICK_MOUSE3,
      EVT_ROLL_UP,
      EVT_ROLL_DOWN,
      EVT_MOVE
    };

    MouseEvent(bool parUp, int parX, int parY, Type parType)
      : BaseEvent(parUp),
        MX(parX),
        MY(parY),
        MDx(0),
        MDy(0),
        MType(parType)
    {
    }

    MouseEvent(int parX, int parY, int parDx, int parDy)
      : BaseEvent(false),
        MX(parX),
        MY(parY),
        MDx(parDx),
        MDy(parDy),
        MType(EVT_MOVE)
    {
    }

    ~MouseEvent() {}

    void Double ()
    {
      switch(MType)
      {
        case EVT_CLICK_MOUSE1:
          MType = EVT_DCLICK_MOUSE1;
        break;
        case EVT_CLICK_MOUSE2:
          MType = EVT_DCLICK_MOUSE2;
        break;
        case EVT_CLICK_MOUSE3:
          MType = EVT_DCLICK_MOUSE3;
        break;
        default:
        break;
      }
    }

    inline int  GetX()    const {return MX;}
    inline int  GetY()    const {return MY;}
    inline int  GetDx()   const {return MDx;}
    inline int  GetDy()   const {return MDy;}
    inline Type GetType() const {return MType;}

  private:
    int MX;
    int MY;
    int MDx;
    int MDy;
    Type MType;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#endif
