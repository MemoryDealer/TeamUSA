// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedAudioActor.cpp
/// \brief Implements DelayedAudioActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "DelayedAudioActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

DelayedAudioActor::DelayedAudioActor(int audioID, int delaySteps = 0 )
: BaseActor( )
{
    // ...
    this->audioId = audioID;
    this->delaySteps = delaySteps;
    this->currentStep = 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

DelayedAudioActor::~DelayedAudioActor(void)
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent DelayedAudioActor::step( Player& player )
{
    // Handle per-frame updates...

    ActorEvent e;
    // Assign data...
    if(this->currentStep == this->delaySteps)
    {
      e.value = this->audioId;
      e.type = PlayAudio;
    }
    this->currentStep++;
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
