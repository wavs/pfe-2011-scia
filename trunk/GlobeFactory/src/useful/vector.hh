////////////////////////////////////////////////////////////////////////////////
// Filename  : vector.hh
// Authors   : Creteur Clement
// Last edit : 01/11/09 - 19h14
// Comment   : Vector definition.
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_VECTOR_HH
#define USEFUL_VECTOR_HH

#include "log.hh"
#include <math.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<unsigned N, typename T>
class Vector
{
  public:
    Vector()
    {
      LOG_ASSERT(N >= 2);
      for (unsigned i = 0; i < N; ++i)
        MValues[i] = static_cast<T>(0);
    }

    Vector(T v)
    {
      LOG_ASSERT(N >= 2);
      for (unsigned i = 0; i < N; ++i)
        MValues[i] = v;
    }

    Vector(const Vector<N, T>& cp)
    {
      for (unsigned i = 0; i < N; ++i)
        MValues[i] = cp.MValues[i];
    }

    ~Vector() {}

    inline Vector<N, T>& operator=(const Vector<N, T>& cp)
    {
      for (unsigned i = 0; i < N; ++i)
        MValues[i] = cp.MValues[i];

      return *this;
    }

    inline T& operator[](unsigned i)
    {
      return GetIth(i);
    }

    inline T& GetIth(unsigned i)
    {
      LOG_ASSERT(i < N);
      return MValues[i];
    }

    inline float LengthSq() const
    {
      float length = 0.0f;
      for (unsigned i = 0; i < N; ++i)
        length += MValues[i] * MValues[i];
      return length;
    }

    inline float Length() const
    {
      return sqrt(LengthSq());
    }

    inline bool IsZero(float precision = 0.01f)
    {
      return LengthSq() < precision;
    }

    inline void Normalize()
    {
      float length = Length();
      LOG_ASSERT(length > 0.01f);
      for (unsigned i = 0; i < N; ++i)
        MValues[i] /= length;
    }

    void operator+=(const Vector<N, T>& vec2)
    {
      for (unsigned i = 0; i < N; ++i)
        MValues[i] += vec2.MValues[i];
    }

    Vector<N, T> operator+(const Vector<N, T>& vec2) const
    {
      Vector<N, T> new_vec;
      for (unsigned i = 0; i < N; ++i)
        new_vec[i] = MValues[i] + vec2.MValues[i];
      return new_vec;
    }

    void operator-=(const Vector<N, T>& vec2)
    {
      for (unsigned i = 0; i < N; ++i)
        MValues[i] -= vec2.MValues[i];
    }

    Vector<N, T> operator-(const Vector<N, T>& vec2) const
    {
      Vector<N, T> new_vec;
      for (unsigned i = 0; i < N; ++i)
        new_vec[i] = MValues[i] - vec2.MValues[i];
      return new_vec;
    }

    void operator*=(T v)
    {
      for (unsigned i = 0; i < N; ++i)
        MValues[i] *= v;
    }

    Vector<N, T> operator*(T v) const
    {
      Vector<N, T> new_vec;
      for (unsigned i = 0; i < N; ++i)
        new_vec[i] = MValues[i] * v;
      return new_vec;

    }

    void operator/=(T v)
    {
      LOG_ASSERT(v != 0);

      for (unsigned i = 0; i < N; ++i)
        MValues[i] /= v;
    }

    Vector<N, T> operator/(T v) const
    {
      Vector<N, T> new_vec;
      for (unsigned i = 0; i < N; ++i)
        new_vec[i] = MValues[i] / v;
      return new_vec;

    }

  ///////////// SPECIALIZED 2 AND 3 DIMENSIONS //////////////////
    Vector(T parX, T parY)
    {
      LOG_ASSERT(N >= 2);

      Set(parX, parY);
    }

    Vector(T parX, T parY, T parZ)
    {
      Set(parX, parY, parZ);
    }

    void Set(T parX, T parY)
    {
      MValues[0] = parX;
      MValues[1] = parY;
    }

    void Set(T parX, T parY, T parZ)
    {
      LOG_ASSERT(N >= 3);

      MValues[0] = parX;
      MValues[1] = parY;
      MValues[2] = parZ;
    }


    inline T x() const {return MValues[0];}
    inline T y() const {return MValues[1];}
    inline T z() const {LOG_ASSERT(N >= 3); return MValues[2];}

    inline T& x() {return MValues[0];}
    inline T& y() {return MValues[1];}
    inline T& z() {LOG_ASSERT(N >= 3); return MValues[2];}


  protected:
    T MValues[N];
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

typedef Vector<3, float> Vector3;
typedef Vector<2, int>   Vector2i;
typedef Vector<2, float> Vector2f;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace BaseVector3
{
  const Vector3 ZERO;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
