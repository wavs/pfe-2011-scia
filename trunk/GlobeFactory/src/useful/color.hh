////////////////////////////////////////////////////////////////////////////////
// Filename  : Color.hh
// Authors   : Creteur Clement
// Last edit : 01/11/09 - 19h34
// Comment   : Color class
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_COLOR_HH
#define USEFUL_COLOR_HH

#include "templated_function.hh"
#include "log.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Color
{
  public:
    Color(float parR = 0.0f, float parG = 0.0f, float parB = 0.0f, float parA = 1.0f)
      : Mr(parR),
        Mg(parG),
        Mb(parB),
        Ma(parA)
    {
      LOG_ASSERT(Mr >= 0.0f && Mr <= 1.0f);
      LOG_ASSERT(Mg >= 0.0f && Mg <= 1.0f);
      LOG_ASSERT(Mb >= 0.0f && Mb <= 1.0f);
      LOG_ASSERT(Ma >= 0.0f && Ma <= 1.0f);
    }

    inline void Negative()
    {
      Mr = 1.0f - Mr;
      Mg = 1.0f - Mg;
      Mb = 1.0f - Mb;
      Ma = 1.0f - Ma;
    }

    inline void Grey()
    {
      Mr = Mg = Mb = (Mr + Mg + Mb) / 3;
    }

    inline void Set(float parR = 0.0f, float parG = 0.0f, float parB = 0.0f, float parA = 1.0f)
    {
      Mr = parR;
      Mg = parG;
      Mb = parB;
      Ma = parA;
      LOG_ASSERT(Mr >= 0.0f && Mr <= 1.0f);
      LOG_ASSERT(Mg >= 0.0f && Mg <= 1.0f);
      LOG_ASSERT(Mb >= 0.0f && Mb <= 1.0f);
      LOG_ASSERT(Ma >= 0.0f && Ma <= 1.0f);
    }

  inline void r(float parR) {Mr = parR; LOG_ASSERT(Mr >= 0.0f && Mr <= 1.0f);}
  inline void g(float parG) {Mg = parG; LOG_ASSERT(Mg >= 0.0f && Mg <= 1.0f);}
  inline void b(float parB) {Mb = parB; LOG_ASSERT(Mb >= 0.0f && Mb <= 1.0f);}
  inline void a(float parA) {Ma = parA; LOG_ASSERT(Ma >= 0.0f && Ma <= 1.0f);}

  inline float r() const {return Mr;}
  inline float g() const {return Mg;}
  inline float b() const {return Mb;}
  inline float a() const {return Ma;}

  private:
    float Mr;
    float Mg;
    float Mb;
    float Ma;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace BaseColor
{
  const Color BLACK = Color(0.0f, 0.0f, 0.0f);
  const Color SNOW = Color(1.0, 0.980, 0.980);
  const Color GHOSTWHITE = Color(0.972, 0.972, 1.0);
  const Color WHITESMOKE = Color(0.960, 0.960, 0.960);
  const Color GAINSBORO = Color(0.862, 0.862, 0.862);
  const Color FLORALWHITE = Color(1.0, 0.980, 0.941);
  const Color OLDLACE = Color(0.992, 0.960, 0.901);
  const Color LINEN = Color(0.980, 0.941, 0.901);
  const Color ANTIQUEWHITE = Color(0.980, 0.921, 0.843);
  const Color PAPAYAWHIP = Color(1.0, 0.937, 0.835);
  const Color BLANCHEDALMOND = Color(1.0, 0.921, 0.803);
  const Color BISQUE = Color(1.0, 0.894, 0.768);
  const Color PEACHPUFF = Color(1.0, 0.854, 0.725);
  const Color NAVAJOWHITE = Color(1.0, 0.870, 0.678);
  const Color MOCCASIN = Color(1.0, 0.894, 0.709);
  const Color CORNSILK = Color(1.0, 0.972, 0.862);
  const Color IVORY = Color(1.0, 1.0, 0.941);
  const Color LEMONCHIFFON = Color(1.0, 0.980, 0.803);
  const Color SEASHELL = Color(1.0, 0.960, 0.933);
  const Color HONEYDEW = Color(0.941, 1.0, 0.941);
  const Color MINTCREAM = Color(0.960, 1.0, 0.980);
  const Color AZURE = Color(0.941, 1.0, 1.0);
  const Color ALICEBLUE = Color(0.941, 0.972, 1.0);
  const Color LAVENDER = Color(0.901, 0.901, 0.980);
  const Color LAVENDERBLUSH = Color(1.0, 0.941, 0.960);
  const Color MISTYROSE = Color(1.0, 0.894, 0.882);
  const Color WHITE = Color(1.0, 1.0, 1.0);
  const Color DARKSLATEGRAY = Color(0.184, 0.309, 0.309);
  const Color DARKSLATEGREY = Color(0.184, 0.309, 0.309);
  const Color DIMGRAY = Color(0.411, 0.411, 0.411);
  const Color DIMGREY = Color(0.411, 0.411, 0.411);
  const Color SLATEGRAY = Color(0.439, 0.501, 0.564);
  const Color SLATEGREY = Color(0.439, 0.501, 0.564);
  const Color LIGHTSLATEGRAY = Color(0.466, 0.533, 0.599);
  const Color LIGHTSLATEGREY = Color(0.466, 0.533, 0.599);
  const Color GRAY = Color(0.745, 0.745, 0.745);
  const Color GREY = Color(0.745, 0.745, 0.745);
  const Color LIGHTGREY = Color(0.827, 0.827, 0.827);
  const Color LIGHTGRAY = Color(0.827, 0.827, 0.827);
  const Color MIDNIGHTBLUE = Color(0.098, 0.098, 0.439);
  const Color NAVY = Color(0.0, 0.0, 0.501);
  const Color NAVYBLUE = Color(0.0, 0.0, 0.501);
  const Color CORNFLOWERBLUE = Color(0.392, 0.584, 0.929);
  const Color DARKSLATEBLUE = Color(0.282, 0.239, 0.545);
  const Color SLATEBLUE = Color(0.415, 0.352, 0.803);
  const Color MEDIUMSLATEBLUE = Color(0.482, 0.407, 0.933);
  const Color LIGHTSLATEBLUE = Color(0.517, 0.439, 1.0);
  const Color MEDIUMBLUE = Color(0.0, 0.0, 0.803);
  const Color ROYALBLUE = Color(0.254, 0.411, 0.882);
  const Color BLUE = Color(0.0, 0.0, 1.0);
  const Color DODGERBLUE = Color(0.117, 0.564, 1.0);
  const Color DEEPSKYBLUE = Color(0.0, 0.749, 1.0);
  const Color SKYBLUE = Color(0.529, 0.807, 0.921);
  const Color LIGHTSKYBLUE = Color(0.529, 0.807, 0.980);
  const Color STEELBLUE = Color(0.274, 0.509, 0.705);
  const Color LIGHTSTEELBLUE = Color(0.690, 0.768, 0.870);
  const Color LIGHTBLUE = Color(0.678, 0.847, 0.901);
  const Color POWDERBLUE = Color(0.690, 0.878, 0.901);
  const Color PALETURQUOISE = Color(0.686, 0.933, 0.933);
  const Color DARKTURQUOISE = Color(0.0, 0.807, 0.819);
  const Color MEDIUMTURQUOISE = Color(0.282, 0.819, 0.800);
  const Color TURQUOISE = Color(0.250, 0.878, 0.815);
  const Color CYAN = Color(0.0, 1.0, 1.0);
  const Color LIGHTCYAN = Color(0.878, 1.0, 1.0);
  const Color CADETBLUE = Color(0.372, 0.619, 0.627);
  const Color MEDIUMAQUAMARINE = Color(0.400, 0.803, 0.666);
  const Color AQUAMARINE = Color(0.498, 1.0, 0.831);
  const Color DARKGREEN = Color(0.0, 0.392, 0.0);
  const Color DARKOLIVEGREEN = Color(0.333, 0.419, 0.184);
  const Color DARKSEAGREEN = Color(0.560, 0.737, 0.560);
  const Color SEAGREEN = Color(0.180, 0.545, 0.341);
  const Color MEDIUMSEAGREEN = Color(0.235, 0.701, 0.443);
  const Color LIGHTSEAGREEN = Color(0.125, 0.698, 0.666);
  const Color PALEGREEN = Color(0.596, 0.984, 0.596);
  const Color SPRINGGREEN = Color(0.0, 1.0, 0.498);
  const Color LAWNGREEN = Color(0.486, 0.988, 0.0);
  const Color GREEN = Color(0.0, 1.0, 0.0);
  const Color CHARTREUSE = Color(0.498, 1.0, 0.0);
  const Color MEDIUMSPRINGGREEN = Color(0.0, 0.980, 0.603);
  const Color GREENYELLOW = Color(0.678, 1.0, 0.184);
  const Color LIMEGREEN = Color(0.196, 0.803, 0.196);
  const Color YELLOWGREEN = Color(0.603, 0.803, 0.196);
  const Color FORESTGREEN = Color(0.133, 0.545, 0.133);
  const Color OLIVEDRAB = Color(0.419, 0.556, 0.137);
  const Color DARKKHAKI = Color(0.741, 0.717, 0.419);
  const Color KHAKI = Color(0.941, 0.901, 0.549);
  const Color PALEGOLDENROD = Color(0.933, 0.909, 0.666);
  const Color LIGHTGOLDENRODYELLOW = Color(0.980, 0.980, 0.823);
  const Color LIGHTYELLOW = Color(1.0, 1.0, 0.878);
  const Color YELLOW = Color(1.0, 1.0, 0.0);
  const Color GOLD = Color(1.0, 0.843, 0.0);
  const Color LIGHTGOLDENROD = Color(0.933, 0.866, 0.509);
  const Color GOLDENROD = Color(0.854, 0.647, 0.125);
  const Color DARKGOLDENROD = Color(0.721, 0.525, 0.043);
  const Color ROSYBROWN = Color(0.737, 0.560, 0.560);
  const Color INDIAN = Color(0.803, 0.360, 0.360);
  const Color INDIANRED = Color(0.803, 0.360, 0.360);
  const Color SADDLEBROWN = Color(0.545, 0.270, 0.074);
  const Color SIENNA = Color(0.627, 0.321, 0.176);
  const Color PERU = Color(0.803, 0.521, 0.247);
  const Color BURLYWOOD = Color(0.870, 0.721, 0.529);
  const Color BEIGE = Color(0.960, 0.960, 0.862);
  const Color WHEAT = Color(0.960, 0.870, 0.701);
  const Color SANDYBROWN = Color(0.956, 0.643, 0.376);
  const Color TAN = Color(0.823, 0.705, 0.549);
  const Color CHOCOLATE = Color(0.823, 0.411, 0.117);
  const Color FIREBRICK = Color(0.698, 0.133, 0.133);
  const Color BROWN = Color(0.647, 0.164, 0.164);
  const Color DARKSALMON = Color(0.913, 0.588, 0.478);
  const Color SALMON = Color(0.980, 0.501, 0.447);
  const Color LIGHTSALMON = Color(1.0, 0.627, 0.478);
  const Color ORANGE = Color(1.0, 0.647, 0.0);
  const Color DARKORANGE = Color(1.0, 0.549, 0.0);
  const Color CORAL = Color(1.0, 0.498, 0.313);
  const Color LIGHTCORAL = Color(0.941, 0.501, 0.501);
  const Color TOMATO = Color(1.0, 0.388, 0.278);
  const Color ORANGERED = Color(1.0, 0.270, 0.0);
  const Color RED = Color(1.0, 0.0, 0.0);
  const Color HOTPINK = Color(1.0, 0.411, 0.705);
  const Color DEEPPINK = Color(1.0, 0.078, 0.576);
  const Color PINK = Color(1.0, 0.752, 0.796);
  const Color LIGHTPINK = Color(1.0, 0.713, 0.756);
  const Color PALEVIOLETRED = Color(0.858, 0.439, 0.576);
  const Color MAROON = Color(0.690, 0.188, 0.376);
  const Color MEDIUMVIOLETRED = Color(0.780, 0.082, 0.521);
  const Color VIOLETRED = Color(0.815, 0.125, 0.564);
  const Color MAGENTA = Color(1.0, 0.0, 1.0);
  const Color VIOLET = Color(0.933, 0.509, 0.933);
  const Color PLUM = Color(0.866, 0.627, 0.866);
  const Color ORCHID = Color(0.854, 0.439, 0.839);
  const Color MEDIUMORCHID = Color(0.729, 0.333, 0.827);
  const Color DARKORCHID = Color(0.599, 0.196, 0.800);
  const Color DARKVIOLET = Color(0.580, 0.0, 0.827);
  const Color BLUEVIOLET = Color(0.541, 0.168, 0.886);
  const Color PURPLE = Color(0.627, 0.125, 0.941);
  const Color MEDIUMPURPLE = Color(0.576, 0.439, 0.858);
  const Color THISTLE = Color(0.847, 0.749, 0.847);
  const Color DARKGREY = Color(0.662, 0.662, 0.662);
  const Color DARKGRAY = Color(0.662, 0.662, 0.662);
  const Color DARKBLUE = Color(0.0, 0.0, 0.545);
  const Color DARKCYAN = Color(0.0, 0.545, 0.545);
  const Color DARKMAGENTA = Color(0.545, 0.0, 0.545);
  const Color DARKRED = Color(0.545, 0.0, 0.0);
  const Color LIGHTGREEN = Color(0.564, 0.933, 0.564);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
