#include "python_gf.hh"
#include "game/state_handler.hh"
#include "game/fps_counter.hh"
#include "game/game_mng.hh"
#include "useful/all.hh"
#include "gfx/gfx_engine.hh"
#include "ui/interface_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

PythonGF::PythonGF()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

PythonGF::~PythonGF()
{
  delete fpsCounter;

  // Attention, l'ordre a de l'importance
  GameMng::kill();
  InterfaceMng::kill();
  GfxEngine::kill();
  StateHandler::kill();
  useful::Kill();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PythonGF::Initialize()
{
  useful::Initialize(0, NULL);

  #ifdef DEBUG
    LOG_RESUME("PythonGF", "DEBUG defined.");
  #else
    LOG_RESUME("PythonGF", "DEBUG not defined.");
  #endif
  #ifdef NDEBUG
    LOG_RESUME("PythonGF", "NDEBUG defined.");
  #else
    LOG_RESUME("PythonGF", "NDEBUG not defined.");
  #endif

  gfxEngine    = GfxEngine::get();
  stateHandler = StateHandler::get();
  inputMng     = InputMng::get();
  gameMng      = GameMng::get();
  interfaceMng = InterfaceMng::get();
  clock        = Clock::get();
  fpsCounter   = new FPSCounter();

  fpsCounter->EnableOnScreen();
  stateHandler->LaunchFirstLoading();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool PythonGF::Frame()
{
  clock->Update();
  inputMng->Update();
  stateHandler->Update();
  gameMng->Update();
  fpsCounter->Update();
  interfaceMng->Update();
  gfxEngine->Update();

  return stateHandler->GetCurrentState() != STATE_QUIT;
}
