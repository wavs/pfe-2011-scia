#include "globe_engine.hh"
#include "game/state_handler.hh"
#include "game/fps_counter.hh"
#include "game/game_mng.hh"
#include "useful/all.hh"
#include "gfx/gfx_engine.hh"
#include "ui/interface_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

GlobeEngine::GlobeEngine()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

GlobeEngine::~GlobeEngine()
{
  // Attention, l'ordre a de l'importance
  GameMng::kill();
  InterfaceMng::kill();
  GfxEngine::kill();
  StateHandler::kill();

  useful::Kill();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void GlobeEngine::Initialize(int argc, char* argv[])
{
  useful::Initialize(argc, argv);

  #ifdef DEBUG
    LOG_RESUME("GlobeEngine", "DEBUG defined.");
  #else
    LOG_RESUME("GlobeEngine", "DEBUG not defined.");
  #endif
  #ifdef NDEBUG
    LOG_RESUME("GlobeEngine", "NDEBUG defined.");
  #else
    LOG_RESUME("GlobeEngine", "NDEBUG not defined.");
  #endif
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int GlobeEngine::Launch()
{
  GfxEngine*    gfxEngine    = GfxEngine::get();
  StateHandler* stateHandler = StateHandler::get();
  InputMng*     inputMng     = InputMng::get();
  GameMng*      gameMng      = GameMng::get();
  InterfaceMng* interfaceMng = InterfaceMng::get();
  Clock*        clock        = Clock::get();

  FPSCounter fpsCounter;
  fpsCounter.EnableOnScreen();
  stateHandler->LaunchFirstLoading();

  while (stateHandler->GetCurrentState() != STATE_QUIT)
  {
    clock->Update();
    inputMng->Update();
    stateHandler->Update();
    gameMng->Update();
    fpsCounter.Update();
    interfaceMng->Update();
    gfxEngine->Update();
  }

  return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
