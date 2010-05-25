#include "intro_cinematic.hh"
#include "../../useful/all.hh"
#include "../../gfx/gfx_engine.hh"
#include "../../gfx/render_window.hh"
#include "../../gfx/renderer_2D.hh"
#include "../../gfx/material_mng.hh"
#include "../../gfx/render_string.hh"
#include "../state_handler.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

IntroCinematic::IntroCinematic()
  : MFadeTime(1.5f),
    MClearTime(3.0f),
    MBgMaterial(0),
    MRenderString(NULL),
    MAnimator(2 * MFadeTime + MClearTime)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

IntroCinematic::~IntroCinematic()
{
  LOG_ASSERT(MRenderString == NULL);
  LOG_ASSERT(MBgMaterial == 0);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void IntroCinematic::Update()
{
  LOG_ASSERT(MRenderString != NULL);

  const Vector2i& reso = GfxEngine::get()->GetWindow()->GetResolution();
  BB2f BB(Vector2f(0.0f, 0.0f), Vector2f(reso.x(), reso.y()));
  GfxEngine::get()->GetPreRender2D()->DrawQuad(BB, MBgMaterial);
  MRenderString->Draw(Vector2f(reso.x() / 2, reso.y() / 2));

  float factor = MAnimator.GetFactor();
  if (factor == 1.0f)
    StateHandler::get()->ChangeState(STATE_MENU, "menu.xml");

  float alpha = 0.0f;
  if (factor < MFadeTime / MAnimator.GetDelay())
    alpha = 1.0f - factor * MAnimator.GetDelay() / (MFadeTime);
  else if (factor < (MClearTime + MFadeTime) / MAnimator.GetDelay())
    alpha = 0.0f;
  else
    alpha = (factor - (MClearTime + MFadeTime) / MAnimator.GetDelay())
            * MAnimator.GetDelay() / MFadeTime;

  if (alpha <= 0.0f) return;
  Color color(0.0f, 0.0f, 0.0f, (alpha <= 1.0f) ? alpha : 1.0f);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB, color);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void IntroCinematic::Start(const std::string& parArg)
{
  MBgMaterial = MaterialMng::get()->LoadMaterial("black.txt");

  MRenderString = new RenderString("candy.ttf", 100);
  MRenderString->Set("- Globe Factory -");
  MRenderString->SetTextSize(100);
  MRenderString->SetAligments(AligmentEnum::MIDDLE, AligmentEnum::CENTER);
  MRenderString->SetColor(BaseColor::RED);
  MRenderString->EnablePreRender();

  MAnimator.Reset();
  MAnimator.Play();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void IntroCinematic::Finish()
{
  MaterialMng::get()->UnloadMaterial(MBgMaterial);
  MBgMaterial = 0;
  delete MRenderString;
  MRenderString = NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
