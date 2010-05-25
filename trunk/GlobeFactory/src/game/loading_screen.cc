#include "loading_screen.hh"
#include "../gfx/material_mng.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/render_window.hh"
#include "../gfx/renderer_2D.hh"
#include "../gfx/renderer_2D.hh"
#include "../gfx/render_string.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

LoadingScreen::LoadingScreen()
  : MBgMaterial(MaterialMng::get()->LoadMaterial("black.txt")),
    MRenderString(new RenderString("candy.ttf", 50)),
    MAnimator(1.0f),
    MAX_OFFSET(8.0f)
{
  MRenderString->Set("Loading");
  MRenderString->SetTextSize(50);
  MRenderString->SetAligments(AligmentEnum::MIDDLE, AligmentEnum::TOP);
  MRenderString->SetColor(BaseColor::WHITE);

  MAnimator.Play();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

LoadingScreen::~LoadingScreen()
{
  MaterialMng::get()->UnloadMaterial(MBgMaterial);
  delete MRenderString;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void LoadingScreen::Update()
{
  const Vector2i& reso = GfxEngine::get()->GetWindow()->GetResolution();
  BB2f BB(Vector2f(0.0f, 0.0f), Vector2f(reso.x(), reso.y()));
  GfxEngine::get()->GetPreRender2D()->DrawQuad(BB, MBgMaterial);

  float factor = MAnimator.GetFactor();
  float offset = -MAX_OFFSET + 2 * MAX_OFFSET * factor;

  if (!MAnimator.IsPlaying())
  {
    if (factor == 1.0f)
      MAnimator.Rewind();
    else
      MAnimator.Play();
  }

  MRenderString->Draw(Vector2f(reso.x() / 2 + offset, 100.0f));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
