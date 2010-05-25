////////////////////////////////////////////////////////////////////////////////
// Filename  : triangle_bag.hh
// Authors   : Creteur Clement
// Last edit : 11/01/10 - 23h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_TRIANGLE_BAG_HH
#define GFX_TRIANGLE_BAG_HH

#include "vertex_writer.hh"
#include "vertex_drawer.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TriangleBag
{
  public:
    TriangleBag();
    ~TriangleBag();

    void Clear();
    void Draw();

    template<class T>
    VertexWriter<T>& GetVertexWriter(unsigned parMaterialId, unsigned parVertexCount, unsigned parTriangleCount);

  private:
    std::map<unsigned, std::vector<BaseVertexDrawer*>* > MVertexDrawers;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "triangle_bag.hxx"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
