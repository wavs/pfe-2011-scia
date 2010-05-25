#include "renderer.hh"
#include "program_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Renderer::Renderer()
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
  {
    MTriangleBags[i] = NULL;
    MTriangleBagsAlpha[i] = NULL;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Renderer::~Renderer()
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
  {
    if (MTriangleBags[i] != NULL)
      delete MTriangleBags[i];
    if (MTriangleBagsAlpha[i] != NULL)
      delete MTriangleBagsAlpha[i];
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer::Draw()
{
  MaterialMng& materialMng = *MaterialMng::get();
  ProgramMng&  programMng  = *ProgramMng::get();

  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
    if (MTriangleBags[i] != NULL)
    {
      programMng.LinkProgram(static_cast<MaterialEnum::Type>(i));
      materialMng.PreRenderForMaterialType(static_cast<MaterialEnum::Type>(i));
      MTriangleBags[i]->Draw();
      materialMng.PostRenderForMaterialType(static_cast<MaterialEnum::Type>(i));
    }

  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
    if (MTriangleBagsAlpha[i] != NULL)
    {
      programMng.LinkProgram(static_cast<MaterialEnum::Type>(i));
      materialMng.PreRenderForMaterialType(static_cast<MaterialEnum::Type>(i));
      MTriangleBagsAlpha[i]->Draw();
      materialMng.PostRenderForMaterialType(static_cast<MaterialEnum::Type>(i));
    }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer::Clear()
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
  {
    if (MTriangleBags[i] != NULL)
      MTriangleBags[i]->Clear();
    if (MTriangleBagsAlpha[i] != NULL)
      MTriangleBagsAlpha[i]->Clear();
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Renderer::Flush()
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
  {
    if (MTriangleBags[i] != NULL)
    {
      delete MTriangleBags[i];
      MTriangleBags[i] = NULL;
    }
    if (MTriangleBagsAlpha[i] != NULL)
    {
      delete MTriangleBagsAlpha[i];
      MTriangleBagsAlpha[i] = NULL;
    }
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
