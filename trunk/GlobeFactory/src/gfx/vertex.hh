////////////////////////////////////////////////////////////////////////////////
// Filename  : vertex.hh
// Authors   : Creteur Clement
// Last edit : 08/01/10 - 18h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_VERTEX_HH
#define GFX_VERTEX_HH

#include <gl/gl.h>
#include "../useful/vector.hh"
#include "../useful/color.hh"

namespace Vertex
{
  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  enum Type
  {
    V3F             = 0,
    C4UB_V3F        = 1,
    N3F_V3F         = 2,
    C4F_N3F_V3F     = 3,
    T2F_V3F         = 4,
    T2F_C4UB_V3F    = 5,
    T2F_N3F_V3F     = 6,
    T2F_C4F_N3F_V3F = 7,
    COUNT           = 8
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  const std::string TypeToString[] =
  {
    "V3F",
    "C4UB_V3F",
    "N3F_V3F",
    "C4F_N3F_V3F",
    "T2F_V3F",
    "T2F_C4UB_V3F",
    "T2F_N3F_V3F",
    "T2F_C4F_N3F_V3F",
    "COUNT (not a vertex type)",
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TV3F
  {
      inline static Type   GetVertexType() {return V3F;}
      inline static GLenum GetOpenGLType() {return GL_V3F;}

      Vector3 position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TC4UB_V3F
  {
      inline static Type   GetVertexType() {return C4UB_V3F;}
      inline static GLenum GetOpenGLType() {return GL_C4UB_V3F;}

      unsigned char color4Ub[4];
      Vector3       position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TN3F_V3F
  {
      inline static Type   GetVertexType() {return N3F_V3F;}
      inline static GLenum GetOpenGLType() {return GL_N3F_V3F;}

      Vector3 normal;
      Vector3 position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TC4F_N3F_V3F
  {
      inline static Type   GetVertexType() {return C4F_N3F_V3F;}
      inline static GLenum GetOpenGLType() {return GL_C4F_N3F_V3F;}

      Color   color4F;
      Vector3 normal;
      Vector3 position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TT2F_V3F
  {
      inline static Type   GetVertexType() {return T2F_V3F;}
      inline static GLenum GetOpenGLType() {return GL_T2F_V3F;}

      Vector2f texCoord;
      Vector3  position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TT2F_C4UB_V3F
  {
      inline static Type   GetVertexType() {return T2F_C4UB_V3F;}
      inline static GLenum GetOpenGLType() {return GL_T2F_C4UB_V3F;}

      Vector2f texCoord;
      unsigned char color4Ub[4];
      Vector3  position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TT2F_N3F_V3F
  {
      inline static Type   GetVertexType() {return T2F_N3F_V3F;}
      inline static GLenum GetOpenGLType() {return GL_T2F_N3F_V3F;}

      Vector2f texCoord;
      Vector3  normal;
      Vector3  position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  struct TT2F_C4F_N3F_V3F
  {
      inline static Type   GetVertexType() {return T2F_C4F_N3F_V3F;}
      inline static GLenum GetOpenGLType() {return GL_T2F_C4F_N3F_V3F;}

      Vector2f texCoord;
      Color    color4F;
      Vector3  normal;
      Vector3  position;
  };

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------
}

#endif
