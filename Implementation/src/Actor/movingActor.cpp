// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file movingActor.cpp
/// \brief Declares movingActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "MovingActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

MovingActor::MovingActor( Region startRegion,Region endregion, int textureId,int layer, int transitionsteps, bool moveOnSpawn )
{
    // ...
	endRegion=endregion;
	transitionSteps = transitionsteps;
	currentStep = 0;
	xSpeed = (endRegion.x - startRegion.x) / transitionSteps;
	ySpeed = (endRegion.y - startRegion.y) / transitionSteps;
	isActive = moveOnSpawn;	
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

MovingActor::~MovingActor( void )
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent MovingActor::onClick( Player& player )
{
    // Handle clicking logic...

    ActorEvent e;
    // Assign data...
	isActive = true;


    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent MovingActor::step()
{
    // Handle per-frame updates...

    ActorEvent e;
    // Assign data...

	int x = mRegion.x;
	int y = mRegion.y;
    if ( isActive ) {
        for ( int i = 0; i < transitionSteps; i++ ) {
            x = x + xSpeed;
            y = y + ySpeed;

            mRegion.x = x;
            mRegion.y = y;
        }
    }

    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //


