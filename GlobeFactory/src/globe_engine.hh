////////////////////////////////////////////////////////////////////////////////
// Filename  : globe_engine.hh
// Authors   : Creteur Clement
// Last edit : 15/11/09 - 20h06
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GLOBE_ENGINE_HH
#define GLOBE_ENGINE_HH

#include "useful/singleton.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class GlobeEngine : public Singleton<GlobeEngine>
{
  friend class Singleton<GlobeEngine>;

  public:
    void Initialize(int argc, char* argv[]);
    int  Launch();

  private:
    GlobeEngine();
    ~GlobeEngine();
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
