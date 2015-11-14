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

ResponsiveAudioActor::ResponsiveAudioActor(Region region, int hoverAudioId = -1, int durationSteps = 120, int clickAudioId = -1 )

{
    m_region = region;
    m_hoverAudioId = hoverAudioId;
    m_durationSteps = durationSteps;
    m_clickAudioId = clickAudioId;
    stepCount = 0;
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
    if(stepCount == m_durationSteps){
       stepCount = 0;
       e.value = m_clickAudioId;
       e.type = PlayAudio;

    }
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::onHover( Player& player )
{
    // Handle hovering logic...
    ActorEvent e;
    if(stepCount == m_durationSteps)
    {
        stepCount = 0;
        e.value = m_hoverAudioId;
        e.eventType = PlayAudio;
    }
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveAudioActor::step( Player& player )
{
    // Handle per-frame updates...
    ActorEvent e;
    while(stepCount != m_durationSteps){
        stepCount++;
    }
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
