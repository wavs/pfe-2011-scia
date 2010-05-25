#include "clock.hh"
#include "timer.hh"
#include "macro.hh"
#include "templated_function.hh"
#include "log.hh"
#include <SDL/SDL.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Clock::Clock()
  : AVERAGE_COUNT(10),
    MElapsTime(0.0f),
    MCurTime(0.0f),
    MStartTime(0.0f)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Clock::~Clock()
{
  LOG_ASSERT(MTimers.empty());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Clock::Initialize()
{
  SDL_Init(SDL_INIT_TIMER);

  MStartTime = SDL_GetTicks() / 1000.0f;
  MCurTime = MStartTime;

  for (unsigned i = 0; i < AVERAGE_COUNT; ++i)
    MElapsTimeQueue.push_back(0.0f);

  MElapsTime = 0.0f;
  LOG_RESUME("Clock  ", "Clock initialized");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Clock::Update()
{
  float curTime = SDL_GetTicks() / 1000.0f;
  float realElapsTime = curTime - MCurTime;

  MElapsTimeQueue.pop_front();
  MElapsTimeQueue.push_back(realElapsTime);

  MElapsTime = 0.0f;
  foreach(it, MElapsTimeQueue)
    MElapsTime += *it;

  MElapsTime /= MElapsTimeQueue.size();

  MCurTime = curTime;

  foreach(it, MTimers)
    (*it)->Update(MElapsTime);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Timer* Clock::CreateTimer()
{
  Timer* timer = new Timer();
  MTimers.push_back(timer);
  return timer;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Clock::DeleteTimer(Timer* parTimer)
{
  LOG_ASSERT(parTimer != NULL);
  LOG_ASSERT(misc::find(parTimer, MTimers));

  MTimers.remove(parTimer);
  delete parTimer;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
