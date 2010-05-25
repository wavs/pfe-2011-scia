////////////////////////////////////////////////////////////////////////////////
// Filename  : out_game_mng.hh
// Authors   : Creteur Clement
// Last edit : 26/11/09 - 21h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef OUT_GAME_MNG_HH
#define OUT_GAME_MNG_HH

#include "../useful/updatable.hh"
#include "state_handler.hh"
#include "state_loadable.hh"
#include "stated_updater.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class LoadingScreen;
class Menu;
class CinematicMng;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class OutGameMng : public Updatable,
                   public StateLoadable<STATE_MENU>
{
  public:
    OutGameMng();
    ~OutGameMng();

    virtual void Update();
    virtual void Load(const std::string parFilename);

  private:
    StatedUpdater  MUpdater;
    LoadingScreen* MLoadingScreen;
    Menu*          MMenu;
    CinematicMng*  MCinematicMng;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
