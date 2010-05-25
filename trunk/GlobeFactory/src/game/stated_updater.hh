////////////////////////////////////////////////////////////////////////////////
// Filename  : stated_updater.hh
// Authors   : Creteur Clement
// Last edit : 17/12/09 - 00h48
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_STATED_UPDATER_HH
#define GAME_STATED_UDPATER_HH

#include "../useful/updatable.hh"
#include "state_handler.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class StatedUpdater : public Updatable
{
  public:
    StatedUpdater();
    virtual ~StatedUpdater();

    virtual void Update();

    void SetStateClient(Updatable* parClient, StateEnum parState);
    void RemoveStateClient(StateEnum parState);

  private:
    Updatable* MClients[STATE_COUNT];
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
