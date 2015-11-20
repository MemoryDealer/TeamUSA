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

ResponsiveAudioActor::ResponsiveAudioActor(Region region, int hoverAudioId = -1, int clickAudioId = -1 )
: BaseActor( region )
{
    this->mRegion = region;
    this->hoverAudioId = hoverAudioId;
    this->clickAudioId = clickAudioId;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveAudioActor::~ResponsiveAudioActor(void)
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::onClick( Player& player )
{
	ActorEvent e;
    e.value = this->clickAudioId;
    e.type = PlayAudio;
	return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::onHover( Player& player )
{
    // Handle hovering logic...
    ActorEvent e;
    e.value = this->hoverAudioId;
    e.type = PlayAudio;
	return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::step( Player& player )
{
    // Handle per-frame updates...
    ActorEvent e;
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
