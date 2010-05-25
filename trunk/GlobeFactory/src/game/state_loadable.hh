////////////////////////////////////////////////////////////////////////////////
// Filename  : state_loadable.hh
// Authors   : Creteur Clement
// Last edit : 12/12/09 - 17h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_STATE_LOADABLE_HH
#define GAME_STATE_LOADABLE_HH

#include "loadable.hh"
#include "state_handler.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


template<StateEnum S>
class StateLoadable : public Loadable
{
  protected:
    StateLoadable()
    {
      StateHandler::get()->RegisterLoadable<S>(this);
    }

    ~StateLoadable()
    {
      StateHandler::get()->UnregisterLoadable<S>(this);
    }
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
