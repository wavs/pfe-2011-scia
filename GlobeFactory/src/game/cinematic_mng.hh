////////////////////////////////////////////////////////////////////////////////
// Filename  : cinematic_mng.hh
// Authors   : Creteur Clement
// Last edit : 20/05/10 - 20h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_CINEMATIC_MNG_HH
#define GAME_CINEMATIC_MNG_HH

#include <string>
#include "../useful/updatable.hh"
#include "state_change_listener.hh"
#include "state_handler.hh"
#include "state_loadable.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Cinematic;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class CinematicMng : public Updatable,
                     public StateLoadable<STATE_CINEMATIC>,
                     public StateChangeListener
{
  public:
    CinematicMng();
    ~CinematicMng();

    virtual void Load(const std::string parArg);
    virtual void Update();

    virtual void OnLeaveCinematic();
    virtual void OnLaunchCinematic();

  private:
    std::map<std::string, Cinematic*> MCinematics;
    Cinematic*                        MCurCinematic;
    std::string                       MArg;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
