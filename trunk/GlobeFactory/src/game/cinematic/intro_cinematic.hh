////////////////////////////////////////////////////////////////////////////////
// Filename  : intro_cinematic.hh
// Authors   : Creteur Clement
// Last edit : 09/04/10 - 17h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_INTRO_CINEMATIC_HH
#define GAME_INTRO_CINEMATIC_HH

#include "cinematic.hh"
#include "../../useful/animator.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Timer;
class RenderString;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class IntroCinematic : public Cinematic
{
  public:
    IntroCinematic();
    ~IntroCinematic();

    void Update();
    void Start(const std::string& parArg = "");
    void Finish();

  private:
    const float   MFadeTime;
    const float   MClearTime;
    unsigned      MBgMaterial;
    RenderString* MRenderString;
    Animator      MAnimator;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
