////////////////////////////////////////////////////////////////////////////////
// Filename  : vertex_drawer.hh
// Authors   : Creteur Clement
// Last edit : 11/01/10 - 23h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_VERTEX_DRAWER_HH
#define GFX_VERTEX_DRAWER_HH

#include "vertex.hh"
#include "vertex_writer.hh"
#include <stdlib.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const unsigned INITIAL_INDEX_COUNT  = 16;
const unsigned INITIAL_VERTEX_COUNT = 16;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class BaseVertexDrawer
{
  public:
    BaseVertexDrawer() {}
    virtual ~BaseVertexDrawer() {}

    virtual Vertex::Type GetVertexType() = 0;
    virtual void Draw()                  = 0;
    virtual void Clear()                 = 0;

    template<class T>
    VertexWriter<T>& GetVertexWriter(unsigned parVertexCount,
                                     unsigned parTriangleCount);

  protected:
    virtual void PrepareVertexWriter(unsigned parVertexCount,
                                     unsigned parTriangleCount) = 0;

    BaseVertexWriter* MVertexWriter;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
class VertexDrawer : public BaseVertexDrawer
{
  public:
    VertexDrawer();
    ~VertexDrawer();

    void Draw();
    void Clear();
    inline Vertex::Type GetVertexType() {return T::GetVertexType();}

  protected:
    void PrepareVertexWriter(unsigned parVertexCount, unsigned parTriangleCount);

  private:
    T*        MVertex;
    unsigned* MIndex;
    unsigned  MVertexCount;
    unsigned  MIndexCount;
    unsigned  MMaxVertex;
    unsigned  MMaxIndex;
    VertexWriter<T>* MTypedVertexWriter;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "vertex_drawer.hxx"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
