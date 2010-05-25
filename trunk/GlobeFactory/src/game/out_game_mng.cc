#include "out_game_mng.hh"
#include "loading_screen.hh"
#include "menu.hh"
#include "cinematic_mng.hh"
#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

OutGameMng::OutGameMng()
  : MLoadingScreen(new LoadingScreen()),
    MMenu(new Menu()),
    MCinematicMng(new CinematicMng())
{
  MUpdater.SetStateClient(MMenu, STATE_MENU);
  MUpdater.SetStateClient(MLoadingScreen, STATE_LOADING);
  MUpdater.SetStateClient(MCinematicMng, STATE_CINEMATIC);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

OutGameMng::~OutGameMng()
{
  delete MMenu;
  delete MLoadingScreen;
  delete MCinematicMng;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void OutGameMng::Update()
{
  MUpdater.Update();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void OutGameMng::Load(const std::string parFilename)
{
  /* FIXME (TEST) */
  unsigned j = 42;
  for (unsigned i = 0; i < 240000000; ++i)
    j *= j - 18 * j;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
