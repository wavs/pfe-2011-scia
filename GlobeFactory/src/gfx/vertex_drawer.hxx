#include "vertex_drawer.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
VertexWriter<T>& BaseVertexDrawer::GetVertexWriter(unsigned parVertexCount,
                                                   unsigned parTriangleCount)
{
  LOG_ASSERT(T::GetVertexType() == GetVertexType());
  LOG_ASSERT(parVertexCount > 0 && parTriangleCount > 0);
  LOG_ASSERT(MVertexWriter != NULL);

  PrepareVertexWriter(parVertexCount, parTriangleCount);
  return static_cast<VertexWriter<T>&>(*MVertexWriter);
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
VertexDrawer<T>::VertexDrawer()
  : MVertex(NULL),
    MIndex(NULL),
    MVertexCount(0),
    MIndexCount(0),
    MMaxVertex(INITIAL_VERTEX_COUNT),
    MMaxIndex(INITIAL_INDEX_COUNT)
{
  MTypedVertexWriter = new VertexWriter<T>();
  MVertexWriter = MTypedVertexWriter;

  MVertex = new T[MMaxVertex];
  MIndex  = new unsigned[MMaxIndex];
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
VertexDrawer<T>::~VertexDrawer()
{
  delete   MVertexWriter;
  delete[] MVertex;
  delete[] MIndex;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
inline void VertexDrawer<T>::Draw()
{
  LOG_ASSERT((MIndexCount % 3) == 0);

  if (MIndexCount != 0)
  {
    glInterleavedArrays(T::GetOpenGLType(), 0, MVertex);
    glDrawElements(GL_TRIANGLES, MIndexCount, GL_UNSIGNED_INT, MIndex);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
inline void VertexDrawer<T>::Clear()
{
  MVertexCount = 0;
  MIndexCount  = 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
void VertexDrawer<T>::PrepareVertexWriter(unsigned parVertexCount,
                                          unsigned parTriangleCount)
{
  LOG_ASSERT(parVertexCount > 0 && parTriangleCount > 0);

  unsigned* index       = NULL;
  T*        vertex      = NULL;
  unsigned  indexCount  = parTriangleCount * 3;
  unsigned  vertexCount = parVertexCount;

  if (MMaxVertex - MVertexCount < vertexCount)
  {
    unsigned lastMax = MMaxVertex;
    do
    {
      MMaxVertex *= 2;
    } while (MMaxVertex - MVertexCount < vertexCount);
    T* newVertex = new T[MMaxVertex];
    memcpy(newVertex, MVertex, sizeof(T) * lastMax);
    delete[] MVertex;
    MVertex = newVertex;
  }

  if (MMaxIndex - MIndexCount < indexCount)
  {
    unsigned lastMax = MMaxIndex;
    do
    {
      MMaxIndex *= 2;
    } while (MMaxIndex - MIndexCount < indexCount);
    unsigned* newIndex = new unsigned[MMaxIndex];
    memcpy(newIndex, MIndex, sizeof(unsigned) * lastMax);
    delete[] MIndex;
    MIndex = newIndex;
  }

  vertex = &MVertex[MVertexCount];
  index  = &MIndex[MIndexCount];
  MTypedVertexWriter->SetMemory(index, indexCount, vertex, vertexCount, MVertexCount);
  MVertexCount += vertexCount;
  MIndexCount  += indexCount;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
