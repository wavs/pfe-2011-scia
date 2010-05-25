#include "timed_updater.hh"
#include "timer.hh"
#include "macro.hh"
#include "log.hh"
#include "templated_function.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TimedUpdater::TimedUpdater(const Timer& parTimer, float parDelay)
  : MTimer(parTimer),
    MUpdateDelay(parDelay),
    MLastUpdate(0.0f)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TimedUpdater::~TimedUpdater()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void TimedUpdater::Update()
{
  if (MTimer.ElapsSince(MLastUpdate) >= MUpdateDelay)
  {
    MLastUpdate = MTimer.GetTimeFromCreation();
    foreach(it, MClients)
      (*it)->Update();
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void TimedUpdater::AddClient(Updatable* parClient)
{
  LOG_ASSERT(parClient != NULL);
  LOG_ASSERT(!misc::find(parClient, MClients));

  MClients.push_back(parClient);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void TimedUpdater::RemoveClient(Updatable* parClient)
{
  LOG_ASSERT(misc::find(parClient, MClients));

  MClients.remove(parClient);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
