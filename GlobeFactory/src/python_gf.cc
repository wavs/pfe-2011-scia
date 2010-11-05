#include "python_gf.hh"
#include "game/state_handler.hh"
#include "game/fps_counter.hh"
#include "game/game_mng.hh"
#include "useful/all.hh"
#include "gfx/gfx_engine.hh"
#include "gfx/material_mng.hh"
#include "gfx/renderer_2D.hh"
#include "ui/interface_mng.hh"
#include "gfx/render_string.hh"

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
  //gameMng->Update();
  fpsCounter->Update();
  interfaceMng->Update();
  gfxEngine->Update();

  return stateHandler->GetCurrentState() != STATE_QUIT;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int PythonGF::LoadMaterial(const std::string& filename)
{
  return (int)MaterialMng::get()->LoadMaterial(filename);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PythonGF::UnloadMaterial(int id)
{
  if (id > 0)
    MaterialMng::get()->UnloadMaterial((unsigned)id);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void PythonGF::DrawQuad(float x, float y, float w, float h, int id)
{
  unsigned mat = (id <= 0) ? 0 : (unsigned)id;
  gfxEngine->GetPostRender2D()->DrawQuad(BB2f(Vector2f(x, y), Vector2f(x+w, y+h)), mat);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PythonGF::DrawLine(float x1, float y1, float x2, float y2, float r, float g, float b)
{
  gfxEngine->GetPostRender2D()->DrawLine(Vector2f(x1, y1),
                                         Vector2f(x2, y2),
                                         Color(r, g, b));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int PythonGF::CreateText2D(const std::string& text, const std::string& font)
{
  RenderString* str = new RenderString(font, 32);
  str->SetText(text);

  int sz = txt2D.size();
  for (int i = 0; i < sz; ++i)
    if (txt2D[i] == NULL)
    {
      txt2D[i] = str;
      return i;
    }

  txt2D.push_back(str);
  return sz;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PythonGF::DeleteText2D(int id)
{
  if (id >= 0 && id < txt2D.size() && txt2D[id] != NULL)
  {
    delete txt2D[id];
    txt2D[id] = NULL;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PythonGF::SetText2DColor(int id, float r, float g, float b)
{
  if (id >= 0 && id < txt2D.size() && txt2D[id] != NULL)
    txt2D[id]->SetColor(Color(r, g, b));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PythonGF::SetText2DSize(int id, float size)
{
  if (id >= 0 && id < txt2D.size() && txt2D[id] != NULL)
    txt2D[id]->SetTextSize(size);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void PythonGF::DrawText2D(int id, float x, float y)
{
  if (id >= 0 && id < txt2D.size() && txt2D[id] != NULL)
    txt2D[id]->Draw(Vector2f(x, y));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
