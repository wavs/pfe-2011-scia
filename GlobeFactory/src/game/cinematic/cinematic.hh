////////////////////////////////////////////////////////////////////////////////
// Filename  : cinematic.hh
// Authors   : Creteur Clement
// Last edit : 09/04/10 - 17h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_CINEMATIC_HH
#define GAME_CINEMATIC_HH

#include <string>
#include "../../useful/updatable.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Cinematic : public Updatable
{
  public:
    Cinematic()          {}
    virtual ~Cinematic() {}

    virtual void Start(const std::string& parArg = "") = 0;
    virtual void Finish() = 0;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
