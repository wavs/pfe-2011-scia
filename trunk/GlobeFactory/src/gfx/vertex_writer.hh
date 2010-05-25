////////////////////////////////////////////////////////////////////////////////
// Filename  : vertex_writer.hh
// Authors   : Creteur Clement
// Last edit : 16/01/10 - 16h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_VERTEX_WRITER_HH
#define GFX_VERTEX_WRITER_HH

#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
class VertexDrawer;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class BaseVertexWriter
{
  public:
    virtual ~BaseVertexWriter() {}

    virtual void AddTriangle(unsigned parI1, unsigned parI2, unsigned parI3) = 0;
    virtual void Finish() = 0;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
class VertexWriter : public BaseVertexWriter
{
  friend class VertexDrawer<T>;

  public:
    T&   GetVertex(unsigned parIth);
    void AddTriangle(unsigned parI1, unsigned parI2, unsigned parI3);
    void Finish();

  private:
    VertexWriter();
    ~VertexWriter();
    void SetMemory(unsigned* parIndex, unsigned parIndexCount,
                   T* parVertex,       unsigned parVertexCount,
                   unsigned parIndexStart);

  private:
    unsigned* MIndex;
    unsigned  MIndexCount;
    T*        MVertex;
    unsigned  MVertexCount;
    unsigned  MCurIndex;
    bool      MIsInitialized;
    unsigned  MIndexStart;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "vertex_writer.hxx"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
