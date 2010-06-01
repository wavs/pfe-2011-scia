#ifndef PY_GLOBE_ENGINE_HH
#define PY_GLOBE_ENGINE_HH

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class GfxEngine;
class StateHandler;
class InputMng;
class GameMng;
class InterfaceMng;
class Clock;
class FPSCounter;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class PythonGF
{
  public:
    PythonGF();
    ~PythonGF();

    void Initialize();
    bool Frame();

  private:
    GfxEngine*    gfxEngine;
    StateHandler* stateHandler;
    InputMng*     inputMng;
    GameMng*      gameMng;
    InterfaceMng* interfaceMng;
    Clock*        clock;
    FPSCounter*   fpsCounter;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
