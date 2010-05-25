////////////////////////////////////////////////////////////////////////////////
// Filename  : animator.hh
// Authors   : Creteur Clement
// Last edit : 02/05/10 - 16h13
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_ANIMATOR_HH
#define USEFUL_ANIMATOR_HH

#include "log.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Timer;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Animator
{
  public:
    Animator(float parDelay, Timer* parTimer = NULL);
    ~Animator();

    void  Play();
    void  Pause();
    void  Rewind();
    void  Reset();
    float GetFactor();

    inline bool  IsPlaying()   const {return MPlay;}
    inline bool  IsRewinding() const {return MRewind;}
    inline float GetDelay()    const {return MDelay;}
    inline void  SetDelay(float parDelay) {LOG_ASSERT(parDelay > 0.0f); MDelay = parDelay;}

  private:
    float  MDelay;
    float  MLastTime;
    float  MFactor;
    bool   MPlay;
    bool   MRewind;
    bool   MOwnTimer;
    Timer* MTimer;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
