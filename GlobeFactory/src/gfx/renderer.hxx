#include "renderer.hh"
#include "material_mng.hh"
#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
inline VertexWriter<T>& Renderer::GetVertexWriter(unsigned parMaterialId,
                                                  unsigned parVertexCount,
                                                  unsigned parTriangleCount)
{
  MaterialEnum::Type matType = MaterialMng::get()->GetMaterialType(parMaterialId);
  LOG_ASSERT(matType != MaterialEnum::COUNT);

  if (MaterialMng::get()->HasAlpha(parMaterialId))
  {
    if (MTriangleBagsAlpha[matType] == NULL)
      MTriangleBagsAlpha[matType] = new TriangleBag();
    return MTriangleBagsAlpha[matType]->GetVertexWriter<T>(parMaterialId,
                                                      parVertexCount,
                                                      parTriangleCount);
  }
  else
  {
    if (MTriangleBags[matType] == NULL)
      MTriangleBags[matType] = new TriangleBag();
    return MTriangleBags[matType]->GetVertexWriter<T>(parMaterialId,
                                                      parVertexCount,
                                                      parTriangleCount);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
