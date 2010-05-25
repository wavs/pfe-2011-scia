////////////////////////////////////////////////////////////////////////////////
// Filename  : state_change_listener.hh
// Authors   : Creteur Clement
// Last edit : 11/11/09 - 16h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_STATE_CHANGE_LISTENER_HH
#define GAME_STATE_CHANGE_LISTENER_HH

#include "../useful/auto_listener.hh"
#include "state_handler.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class StateChangeListener : public AutoListener<StateChangeListener, StateHandler>
{
  public:
    StateChangeListener() {}
    virtual ~StateChangeListener() {}

    inline virtual void OnLeaveMenu()       {}
    inline virtual void OnLeaveIngame()     {}
    inline virtual void OnLeaveCinematic()  {}
    inline virtual void OnLeaveLoading()    {}

    inline virtual void OnLaunchMenu()      {}
    inline virtual void OnLaunchIngame()    {}
    inline virtual void OnLaunchCinematic() {}
    inline virtual void OnLaunchLoading()   {}
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
