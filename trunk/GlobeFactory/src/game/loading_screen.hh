////////////////////////////////////////////////////////////////////////////////
// Filename  : loading_screen.hh
// Authors   : Creteur Clement
// Last edit : 25/04/10 - 18h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_LOADING_SCREEN_HH
#define GAME_LOADING_SCREEN_HH

#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class RenderString;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class LoadingScreen : public Updatable
{
  public:
    LoadingScreen();
    ~LoadingScreen();

    virtual void Update();

  private:
    unsigned       MBgMaterial;
    RenderString*  MRenderString;
    Animator       MAnimator;
    const float    MAX_OFFSET;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
