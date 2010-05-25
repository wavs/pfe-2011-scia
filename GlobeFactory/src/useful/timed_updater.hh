////////////////////////////////////////////////////////////////////////////////
// Filename  : timed_updater.hh
// Authors   : Creteur Clement
// Last edit : 11/11/09 - 15h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_TIMED_UPDATER_HH
#define USEFUL_TIMED_UDPATER_HH

#include <list>
#include "updatable.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Timer;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TimedUpdater : public Updatable
{
  public:
    TimedUpdater(const Timer& parTimer, float parDelay = 0.0f);
    virtual ~TimedUpdater();

    virtual void Update();

    void AddClient(Updatable* parClient);
    void RemoveClient(Updatable* parClient);

    inline void  SetUpdateDelay(float parDelay) {MUpdateDelay = parDelay;}
    inline float GetUpdateDelay() const         {return MUpdateDelay;}

  private:
    std::list<Updatable*> MClients;
    const Timer&          MTimer;
    float                 MUpdateDelay;
    float                 MLastUpdate;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
