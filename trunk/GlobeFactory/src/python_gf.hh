#ifndef PY_GLOBE_ENGINE_HH
#define PY_GLOBE_ENGINE_HH

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <string>
#include <vector>

class GfxEngine;
class StateHandler;
class InputMng;
class GameMng;
class InterfaceMng;
class Clock;
class FPSCounter;
class RenderString;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class PythonGF
{
  public:
    PythonGF();
    ~PythonGF();

    void Initialize();
    bool Frame();

    int LoadMaterial(const std::string& filename);
    void UnloadMaterial(int id);

    void DrawQuad(float x, float y, float w, float h, int id);
    void DrawLine(float x1, float y1, float x2, float y2, float r = 0.5f, float g = 0.5f, float b = 0.5f);

    int CreateText2D(const std::string& text, const std::string& font);
    void DeleteText2D(int id);
    void DrawText2D(int id, float x, float y);
    void SetText2DColor(int id, float r, float g, float b);
    void SetText2DSize(int id, float size);

  private:
    GfxEngine*    gfxEngine;
    StateHandler* stateHandler;
    InputMng*     inputMng;
    GameMng*      gameMng;
    InterfaceMng* interfaceMng;
    Clock*        clock;
    FPSCounter*   fpsCounter;

    std::vector<RenderString*> txt2D;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
