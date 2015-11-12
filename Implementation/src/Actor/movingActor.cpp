// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file movingActor.cpp
/// \brief Declares movingActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "movingActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

movingActor::movingActor( Region startRegion,Region endregion, int textureId,int layer, int transitionsteps, bool moveOnSpawn )
{
    // ...
	endRegion=endregion;
	transitionSteps = transitionsteps;
	currentStep = 0;
	xSpeed = 0;
	ySpeed = 0;
	isActive = moveOnSpawn;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

movingActor::~movingActor( void )
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent movingActor::onClick( Player& player )
{
    // Handle clicking logic...

    ActorEvent e;
    // Assign data...
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent movingActor::onHover( Player& player )
{
    // Handle hovering logic...

    ActorEvent e;
    // Assign data...
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent movingActor::step( Player& player )
{
    // Handle per-frame updates...

    ActorEvent e;
    // Assign data...
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //


