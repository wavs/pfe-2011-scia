#include "fps_counter.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/window_opengl_sdl.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

FPSCounter::FPSCounter()
  : MTimer(NULL),
    MOnLog(false),
    MOnScreen(false),
    MFPS(0),
    MLastFPS(0),
    MBeginTime(0.0f),
    MRenderStr("arial.ttf", 32)
{
  MTimer = Clock::get()->CreateTimer();

  MRenderStr.Set("...");
  MRenderStr.SetColor(BaseColor::BLUE);
  MRenderStr.SetAligments(AligmentEnum::LEFT, AligmentEnum::BOTTOM);
  MRenderStr.SetTextSize(18.0f);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

FPSCounter::~FPSCounter()
{
  Clock::get()->DeleteTimer(MTimer);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void FPSCounter::Update()
{
  if (MOnScreen)
  {
    if (MTimer->ElapsSince(MBeginTime) >= 1.0f)
      MRenderStr.SetText(misc::ToString(MLastFPS) + "fps");
    const Vector2i& resolution = GfxEngine::get()->GetWindow()->GetResolution();
    MRenderStr.Draw(Vector2f(resolution.x(), resolution.y()));
  }

  if (MTimer->ElapsSince(MBeginTime) >= 1.0f)
  {
    MBeginTime = MTimer->GetTimeFromCreation();
    MLastFPS = MFPS;

    if (MOnLog)
      LOG_RESUME("FPS Counter", misc::ToString(MFPS) + " FPS.");

    MFPS = 0;
  }
  else
    ++MFPS;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
