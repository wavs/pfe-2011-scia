////////////////////////////////////////////////////////////////////////////////
// Filename  : bounding_box.hh
// Authors   : Creteur Clement
// Last edit : 29/12/09 - 22h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_BOUNDING_BOX_HH
#define USEFUL_BOUNDING_BOX_HH

#include "vector.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<typename T>
class BB2
{
  public:
    BB2()
    {
    }

    BB2(const Vector<2, T>& parMin, const Vector<2, T>& parMax)
      : MMin(parMin),
        MMax(parMax)
    {
    }

  inline const Vector<2, T>& Min() const {return MMin;}
  inline const Vector<2, T>& Max() const {return MMax;}

  inline Vector<2, T>& Min() {return MMin;}
  inline Vector<2, T>& Max() {return MMax;}

  bool IsPosIn(const Vector<2, T>&) const;

  private:
    Vector<2, T> MMin;
    Vector<2, T> MMax;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class BB3f
{
  public:
    BB3f()
    {
    }

    BB3f(const Vector3& parMin, const Vector3& parMax)
      : MMin(parMin),
        MMax(parMax)
    {
    }

  inline const Vector3& Min() const {return MMin;}
  inline const Vector3& Max() const {return MMax;}

  inline Vector3& Min() {return MMin;}
  inline Vector3& Max() {return MMax;}

  private:
    Vector3 MMin;
    Vector3 MMax;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "bounding_box.hxx"

typedef BB2<int>   BB2i;
typedef BB2<float> BB2f;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
