#include "state_handler.hh"
#include "state_change_listener.hh"
#include "../useful/all.hh"
#include <boost/thread/thread.hpp>
#include "../gfx/gfx_engine.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

StateHandler::StateHandler()
  : MCurrentState(STATE_CINEMATIC),
    MNextState(STATE_MENU),
    MLoadingAdvance(1.0f)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

StateHandler::~StateHandler()
{
  for (unsigned i = 0; i < STATE_COUNT; ++i)
    LOG_ASSERT(MLoadables[i].empty());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void StateHandler::ChangeState(StateEnum parState, const std::string& parFile)
{
  if (MNextState != STATE_COUNT)
  {
    LOG_ERROR("StateHndlr", "Try to change the game state several times in a frame.");
  }
  else
  {
    MNextState = parState;
    MFileToLoad = parFile;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void StateHandler::Update()
{
  if (MNextState != STATE_COUNT)
  {
    if (MCurrentState != STATE_LOADING)
    {
      LOG_RESUME("State Handler", "Launch loading of state " + StateEnumStr[MNextState]);
      LeaveState(MCurrentState);
      MCurrentState = STATE_LOADING;
      LaunchState(MCurrentState);
      MLoadingAdvance = 0.0f;
      LaunchLoading(MNextState, MFileToLoad);
    }
    else
    {
      MLoadingAdvance = 0.0f;
      unsigned nbLoadables = MLoadables[MNextState].size();
      std::list<Loadable*>& loadables = MLoadables[MNextState];
      foreach(it, loadables)
        if ((*it)->IsLoaded())
          MLoadingAdvance += 1.0f;

      if (nbLoadables != 0)
        MLoadingAdvance /= nbLoadables;
      else
        MLoadingAdvance = 1.0f;

      if (MLoadingAdvance >= 1.0f)
      {
        LOG_RESUME("State Handler", "Loading finished, begin state " + StateEnumStr[MNextState]);
        LeaveState(MCurrentState);
        MCurrentState = MNextState;
        LaunchState(MCurrentState);
        MNextState = STATE_COUNT;
        GfxEngine::get()->Flush(); // Reset the engine in the initial state
      }
    }
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void StateHandler::LeaveState(StateEnum parState)
{
  switch (parState)
  {
    case STATE_MENU:
      foreach(it, MClients)
        (*it)->OnLeaveMenu();
    break;
    case STATE_INGAME:
      foreach(it, MClients)
        (*it)->OnLeaveIngame();
    break;
    case STATE_CINEMATIC:
      foreach(it, MClients)
        (*it)->OnLeaveCinematic();
    break;
    case STATE_LOADING:
      foreach(it, MClients)
        (*it)->OnLeaveLoading();
    break;
    default:
    break;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void StateHandler::LaunchState(StateEnum parState)
{
  switch (parState)
  {
    case STATE_MENU:
      foreach(it, MClients)
        (*it)->OnLaunchMenu();
    break;
    case STATE_INGAME:
      foreach(it, MClients)
        (*it)->OnLaunchIngame();
    break;
    case STATE_CINEMATIC:
      foreach(it, MClients)
        (*it)->OnLaunchCinematic();
    break;
    case STATE_LOADING:
      foreach(it, MClients)
        (*it)->OnLaunchLoading();
    break;
    default:
    break;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void StateHandler::LaunchLoading(StateEnum parState, const std::string& parFile)
{
  std::list<Loadable*>& loadables = MLoadables[parState];
  foreach(it, loadables)
  {
    (*it)->PrepareLoading(parFile);
    boost::thread new_thread(boost::ref(*(*it)));
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void StateHandler::LaunchFirstLoading()
{
  ConfigMng* cfgMng = ConfigMng::get();

  unsigned fileId = cfgMng->Load("launch.cfg");
  const std::string* state = cfgMng->GetOptionStr(fileId, "state");
  const std::string* arg  = cfgMng->GetOptionStr(fileId, "arg");

  if (state == NULL || arg == NULL)
  {
    LOG_ERROR("State Handler", "Error in the launch.cfg file.");
    MCurrentState = STATE_QUIT;
    return;
  }

  StateEnum firstState = STATE_COUNT;

  for (unsigned i = 0; i < STATE_COUNT; ++i)
    {
      if (StateEnumStr[i] ==  *state)
	{
	  firstState = static_cast<StateEnum> (i);
	  break;
        }
    }
  if (firstState == STATE_COUNT)
  {
    LOG_ERROR("State Handler", "Error unknow state in launch.cfg.");
    MCurrentState = STATE_QUIT;
    return;
  }

  MCurrentState = STATE_LOADING;
  MNextState = firstState;
  MFileToLoad = *arg;
  LaunchState(STATE_LOADING);
  MLoadingAdvance = 0.0f;
  LaunchLoading(MNextState, MFileToLoad);

  cfgMng->Unload(fileId);

  LOG_RESUME("State Handler", "Start GlobeEngine with state " + StateEnumStr[MNextState]);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
