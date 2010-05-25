////////////////////////////////////////////////////////////////////////////////
// Filename  : menu.hh
// Authors   : Creteur Clement
// Last edit : 20/05/10 - 20h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_MENU_HH
#define GAME_MENU_HH

#include "../useful/all.hh"
#include "state_change_listener.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Menu : public Updatable,
             public StateChangeListener
{
  public:
    Menu();
    ~Menu();

    virtual void OnLeaveMenu();
    virtual void OnLaunchMenu();

    virtual void Update();

  private:
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
