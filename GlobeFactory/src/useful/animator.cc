#include "animator.hh"
#include "timer.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Animator::Animator(float parDelay, Timer* parTimer)
  : MDelay(parDelay),
    MLastTime(0.0f),
    MFactor(0.0f),
    MPlay(false),
    MRewind(false),
    MOwnTimer(parTimer == NULL),
    MTimer((parTimer == NULL) ? Clock::get()->CreateTimer() : parTimer)
{
  LOG_ASSERT(MDelay > 0.0f);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Animator::~Animator()
{
  if (MOwnTimer)
    Clock::get()->DeleteTimer(MTimer);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Animator::Play()
{
  LOG_ASSERT(MPlay == false);

  MPlay = true;
  MRewind = false;
  MLastTime = MTimer->GetTimeFromCreation();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Animator::Pause()
{
  LOG_ASSERT(MPlay == true);

  MPlay = false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Animator::Rewind()
{
  LOG_ASSERT(MPlay == false);
  LOG_ASSERT(MRewind == false);

  MPlay   = true;
  MRewind = true;
  MLastTime = MTimer->GetTimeFromCreation();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Animator::Reset()
{
  MPlay   = false;
  MRewind = false;
  MFactor = 0.0f;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

float Animator::GetFactor()
{
  if (MPlay)
  {
    LOG_ASSERT(MDelay > 0.0f);

    if (MRewind)
      MFactor -= MTimer->ElapsSince(MLastTime) / MDelay;
    else
      MFactor += MTimer->ElapsSince(MLastTime) / MDelay;

    MLastTime = MTimer->GetTimeFromCreation();

    if (MFactor <= 0.0f && MRewind)
    {
      MPlay = false;
      MFactor = 0.0f;
    }
    else if (MFactor >= 1.0f)
    {
      MPlay = false;
      MFactor = 1.0f;
    }
  }
  return MFactor;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
