#include "triangle_bag.hh"
#include "../useful/log.hh"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
VertexWriter<T>& TriangleBag::GetVertexWriter(unsigned parMaterialId, unsigned parVertexCount, unsigned parTriangleCount)
{
  std::vector<BaseVertexDrawer*>* tabPVD = NULL;

  if (MVertexDrawers.count(parMaterialId) == 0)
  {
    tabPVD = new std::vector<BaseVertexDrawer*>;
    tabPVD->reserve(Vertex::COUNT);
    for (unsigned i = 0; i < Vertex::COUNT; ++i)
      (*tabPVD)[i] = NULL;
    MVertexDrawers[parMaterialId] = tabPVD;
    LOG_RESUME("TriangleBag", "Creation of new vertexDrawer for material : " + misc::ToString(parMaterialId));
  }

  tabPVD = MVertexDrawers[parMaterialId];

  BaseVertexDrawer* vd = (*tabPVD)[T::GetVertexType()];

  if (vd == NULL)
  {
    vd = new VertexDrawer<T>();
    (*tabPVD)[T::GetVertexType()] = vd;
  }

  return vd->GetVertexWriter<T>(parVertexCount, parTriangleCount);
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
