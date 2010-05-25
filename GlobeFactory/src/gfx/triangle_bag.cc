#include "triangle_bag.hh"
#include "material_mng.hh"
#include "vertex_drawer.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TriangleBag::TriangleBag()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TriangleBag::~TriangleBag()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void TriangleBag::Clear()
{
  foreach(it, MVertexDrawers)
  {
    for (unsigned i = 0; i < Vertex::COUNT; ++i)
    {
      BaseVertexDrawer* vd = (*(it->second))[i];
      if (vd != NULL)
        vd->Clear();
    }
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void TriangleBag::Draw()
{
  MaterialMng& materialMng = *MaterialMng::get();

  foreach(it, MVertexDrawers)
  {
    materialMng.PreRenderForMaterial(it->first);
    for (unsigned i = 0; i < Vertex::COUNT; ++i)
    {
      BaseVertexDrawer* vd = (*(it->second))[i];
      if (vd != NULL)
        vd->Draw();
    }
    materialMng.PostRenderForMaterial(it->first);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
