// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file ResponsiveAudioActor.cpp
/// \brief Implements ResponsiveAudioActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "ResponsiveAudioActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace USA; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveAudioActor::ResponsiveAudioActor( region: Region, hoverAudioId = -1, durationSteps = 120, clickAudioId = -1 )
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveAudioActor::~ResponsiveAudioActor( void )
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::onClick( Player& player )
{
    // Handle clicking logic...

    ActorEvent e;
    // Assign data...
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::onHover( Player& player )
{
    // Handle hovering logic...

    ActorEvent e;
    // Assign data...
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::step( Player& player )
{
    // Handle per-frame updates...

    ActorEvent e;
    // Assign data...
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
