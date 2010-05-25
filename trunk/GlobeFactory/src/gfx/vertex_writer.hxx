#include "vertex_writer.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
VertexWriter<T>::VertexWriter()
  : MIndex(NULL),
    MIndexCount(0),
    MVertex(NULL),
    MVertexCount(0),
    MIsInitialized(false),
    MIndexStart(0)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
VertexWriter<T>::~VertexWriter()
{
  LOG_ASSERT(MIsInitialized == false);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
inline T& VertexWriter<T>::GetVertex(unsigned parIth)
{
  LOG_ASSERT(MIsInitialized);
  LOG_ASSERT(parIth < MVertexCount);

  return MVertex[parIth];
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
inline void VertexWriter<T>::AddTriangle(unsigned parI1, unsigned parI2, unsigned parI3)
{
  LOG_ASSERT(MIsInitialized);
  LOG_ASSERT(MCurIndex < (MIndexCount - 2));
  LOG_ASSERT(parI1 < MVertexCount &&
             parI2 < MVertexCount &&
             parI3 < MVertexCount);


  MIndex[MCurIndex + 0] = MIndexStart + parI1;
  MIndex[MCurIndex + 1] = MIndexStart + parI2;
  MIndex[MCurIndex + 2] = MIndexStart + parI3;
  MCurIndex += 3;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
inline void VertexWriter<T>::Finish()
{
  LOG_ASSERT(MIsInitialized == true);
  LOG_ASSERT(MCurIndex == MIndexCount);
  MIsInitialized = false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
inline void VertexWriter<T>::SetMemory(unsigned* parIndex,
                                       unsigned parIndexCount,
                                       T* parVertex,
                                       unsigned parVertexCount,
                                       unsigned parIndexStart)
{
  LOG_ASSERT(MIsInitialized == false);
  LOG_ASSERT(parVertexCount >= 3 && parIndexCount > 0);

  MIndex = parIndex;
  MIndexCount = parIndexCount;
  MVertex = parVertex;
  MVertexCount = parVertexCount;
  MCurIndex = 0;
  MIndexStart = parIndexStart;

  MIsInitialized = true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
