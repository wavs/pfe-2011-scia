////////////////////////////////////////////////////////////////////////////////
// Filename  : clock.hh
// Authors   : Creteur Clement
// Last edit : 01/11/09 - 19h34
// Comment   : Main class managing the time. Reducing the system call and making
//             more simple the concept of time in the software. It should be
//             used as a Timer factory and should be updated each frame.
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_CLOCK_HH
#define USEFUL_CLOCK_HH

#include <deque>
#include <list>
#include "singleton.hh"

class Timer;

class Clock : public Singleton<Clock>
{
  friend class Singleton<Clock>;

  public:
    void   Initialize();
    void   Update();

    Timer* CreateTimer();
    void   DeleteTimer(Timer* parTimer);

    inline float  GetCurTime()   const {return MCurTime;}
    inline float  GetElapsTime() const {return MElapsTime;}
    inline float  GetStartTime() const {return MStartTime;}

  private:
    Clock();
    ~Clock();

    const unsigned    AVERAGE_COUNT;
    std::deque<float> MElapsTimeQueue;
    float             MElapsTime;
    float             MCurTime;
    float             MStartTime;
    std::list<Timer*> MTimers;
};

#endif
