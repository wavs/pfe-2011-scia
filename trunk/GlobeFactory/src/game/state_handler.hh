////////////////////////////////////////////////////////////////////////////////
// Filename  : state_handler.hh
// Authors   : Creteur Clement
// Last edit : 11/11/09 - 16h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_STATE_HANDLER_HH
#define GAME_STATE_HANDLER_HH

#include "../useful/all.hh"
#include "loadable.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class StateChangeListener;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

enum StateEnum
{
  STATE_MENU        = 0,
  STATE_INGAME      = 1,
  STATE_CINEMATIC   = 2,
  STATE_LOADING     = 3,
  STATE_QUIT        = 4,
  STATE_COUNT       = 5
};

const std::string StateEnumStr[] =
{
  "MENU",
  "INGAME",
  "CINEMATIC",
  "LOADING",
  "QUIT",
  "COUNT (Not a State)",
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class StateHandler : public Singleton<StateHandler>,
                     public Notifier<StateChangeListener>,
                     public Updatable
{
  friend class Singleton<StateHandler>;

  public:
    template<StateEnum S>
    inline void RegisterLoadable(Loadable* parClient)
    {
      LOG_ASSERT(S != STATE_COUNT);
      LOG_ASSERT(parClient != NULL);
      LOG_ASSERT(!misc::find(parClient, MLoadables[S]));
      MLoadables[S].push_back(parClient);
    }

    template<StateEnum S>
    inline void UnregisterLoadable(Loadable* parClient)
    {
      LOG_ASSERT(S != STATE_COUNT);
      LOG_ASSERT(misc::find(parClient, MLoadables[S]));
      MLoadables[S].remove(parClient);
    }

    StateEnum GetCurrentState() const {return MCurrentState;}
    void      ChangeState(StateEnum parState, const std::string& parFile = "");
    void      Update();
    void      LaunchFirstLoading();

  private:
    StateHandler();
    ~StateHandler();

    void LeaveState(StateEnum parState);
    void LaunchState(StateEnum parState);
    void LaunchLoading(StateEnum parState, const std::string& parFile);

    std::list<Loadable*> MLoadables[STATE_COUNT];
    StateEnum            MCurrentState;
    StateEnum            MNextState;
    std::string          MFileToLoad;
    float                MLoadingAdvance;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
