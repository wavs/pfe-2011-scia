#include "gfx_engine.hh"
#include "../useful/all.hh"
#include "texture_mng.hh"
#include "window_opengl_sdl.hh"
#include "renderer_3D.hh"
#include "renderer_2D.hh"
#include "../ui/interface_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

GfxEngine::GfxEngine()
{
  MWindow = new WindowOpenglSDL();

  MPreRender2D  = new Renderer2D();
  MPostRender2D = new Renderer2D();
  MRender3D     = new Renderer3D();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

GfxEngine::~GfxEngine()
{
  MaterialMng::kill();
  TextureMng::kill();

  delete MPreRender2D;
  delete MPostRender2D;
  delete MRender3D;
  delete MWindow;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void GfxEngine::Update()
{
  MWindow->PreRender();

  MPreRender2D->PreRender();
  MPreRender2D->Draw();
  MPreRender2D->PostRender();
  MPreRender2D->Clear();

  MRender3D->PreRender();
  MRender3D->Draw();
  MRender3D->PostRender();
  MRender3D->Clear();

  MPostRender2D->PreRender();
  MPostRender2D->Draw();
  MPostRender2D->PostRender();
  MPostRender2D->Clear();

  MWindow->PostRender();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void GfxEngine::Flush()
{
  MPreRender2D->Flush();
  MRender3D->Flush();
  MPostRender2D->Flush();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
