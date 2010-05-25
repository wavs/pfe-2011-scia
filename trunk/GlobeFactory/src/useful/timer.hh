////////////////////////////////////////////////////////////////////////////////
// Filename  : timer.hh
// Authors   : Creteur Clement
// Last edit : 01/11/09 - 19h34
// Comment   : The instances of this class are created/deleted by the Clock
//             singleton. It allows to manage the time from different point of
//             views. For example, a timer can be slowed down (scale the flow
//             of the time) or can be paused, independently of the other timers.
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_TIMER_HH
#define USEFUL_TIMER_HH

#include "clock.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Timer
{
  friend class Clock;

  public:
    Timer*       CreateTimer();
    void         DeleteTimer(Timer* parTimer);
    void         Restart();

    inline float GetTimeFromCreation() const {return MTimeFromCreation;}
    inline float GetScale()            const {return MScale;}
    inline float GetElapsTime()        const {return MElapsTime;}
    inline bool  IsPaused()            const {return MPause;}
    inline void  TogglePause()               {MPause = !MPause;}

    inline void  SetScale(float parScale) {MScale = parScale;}
    inline void  SetPause(bool parPause)  {MPause = parPause;}

    inline float ElapsSince (float parSince) const {return MTimeFromCreation - parSince;}

  private:
    Timer();
    ~Timer();
    void Update(float parElapsTime);

    float MElapsTime;
    float MScale;
    float MTimeFromCreation;
    bool  MPause;

    std::list<Timer*> MTimers;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
