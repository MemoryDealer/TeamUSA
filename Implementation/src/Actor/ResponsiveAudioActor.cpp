// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file ResponsiveAudioActor.cpp
/// \brief Implements ResponsiveAudioActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "ResponsiveAudioActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveAudioActor::ResponsiveAudioActor(Region region, int hoverAudioId = -1, int durationSteps = 120, int clickAudioId = -1 )
: BaseActor( region )
{
    this->mRegion = region;
    this->hoverAudioId = hoverAudioId;
    this->durationSteps = durationSteps;
    this->clickAudioId = clickAudioId;
    this->stepCount = 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveAudioActor::~ResponsiveAudioActor(void)
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::onClick( Player& player )
{
    // Handle clicking logic...
    ActorEvent e;
    if(this->stepCount == this->durationSteps){
       this->stepCount = 0;
       e.value = this->clickAudioId;
       e.type = PlayAudio;

    }
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::onHover( Player& player )
{
    // Handle hovering logic...
    ActorEvent e;
    if(this->stepCount == this->durationSteps)
    {
        this->stepCount = 0;
        e.value = this->hoverAudioId;
        e.type = PlayAudio;
    }
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::step( Player& player )
{
    // Handle per-frame updates...
    ActorEvent e;
    if(this->stepCount != this->durationSteps){
        this->stepCount++;
    }
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
