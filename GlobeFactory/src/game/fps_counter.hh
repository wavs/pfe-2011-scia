////////////////////////////////////////////////////////////////////////////////
// Filename  : fps_counter.hh
// Authors   : Creteur Clement
// Last edit : 02/02/10 - 20h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_FPS_COUNTER_HH
#define GAME_FPS_COUNTER_HH

#include "../useful/all.hh"
#include "../gfx/render_string.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class FPSCounter : public Updatable
{
  public:
    FPSCounter();
    ~FPSCounter();

    void Update();

    inline void EnableOnLog()     {MOnLog = true;}
    inline void DisableOnLog()    {MOnLog = false;}
    inline void EnableOnScreen()  {MOnScreen = true;}
    inline void DisableOnScreen() {MOnScreen = false;}

  private:
    Timer*       MTimer;
    bool         MOnLog;
    bool         MOnScreen;
    unsigned     MFPS;
    unsigned     MLastFPS;
    float        MBeginTime;
    RenderString MRenderStr;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
