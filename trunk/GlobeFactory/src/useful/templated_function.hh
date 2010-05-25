////////////////////////////////////////////////////////////////////////////////
// Filename  : templated_function.hh
// Authors   : Creteur Clement
// Last edit : 02/10/09 - 19h34
// Comment   : misc...
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_TEMPLATED_FUNCTION_HH
#define USEFUL_TEMPLATED_FUNCTION_HH

#include <sstream>

namespace misc
{
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

  template<class Container>
  inline bool find(typename Container::value_type x, Container& c)
  {
    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator end = c.end();

    for(;it != end; ++it)
      if (*it == x)
        return true;

    return false;
  }

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

  template<class T>
  inline T Interval(T val, T min, T max)
  {
    if (val >= max) return max;
    if (val <= min) return min;
    return val;
  }

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

  template <class T>
  inline bool FromString(T& t, const std::string& s)
  {
    std::istringstream iss(s);
    return !(iss >> t).fail();
  }

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

  template <class T>
  inline std::string ToString(const T& t)
  {
    std::ostringstream ss;
    ss << t;
    return ss.str();
  }

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

  inline bool CharEqual(char c1, char c2)
  {
    if (c1 == c2)
      return true;
    c1 = (c1 >= 'a' && c1 <= 'z') ? c1 - 32: c1;
    c2 = (c2 >= 'a' && c2 <= 'z') ? c2 - 32: c2;
    return c1 == c2;
  }

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

  inline bool StrEqual(const std::string& s1, const std::string& s2)
  {
    unsigned sz1 = s1.length();

    if (sz1 != s2.length())
      return false;

    for (unsigned i = 0; i < sz1; ++i)
      if (!CharEqual(s1[i], s2[i]))
        return false;

    return true;
  }

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
}

#endif
