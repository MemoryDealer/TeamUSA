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
	xSpeed = (endRegion.x - startRegion.x) / transitionSteps;
	ySpeed = (endRegion.y - startRegion.y) / transitionSteps;
	isActive = moveOnSpawn;

	if (isActive) {
		step();
	}
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
	int x = mRegion.x;
	int y = mRegion.y;
	for (int i = 0; i < transitionSteps; i++) {
		x = x + xSpeed;
		y = y + ySpeed;

		mRegion.x = x;
		mRegion.y = y;

		setRegion(mRegion);
	}


    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent movingActor::step()
{
    // Handle per-frame updates...

    ActorEvent e;
    // Assign data...

	int x = mRegion.x;
	int y = mRegion.y;
	for (int i = 0; i < transitionSteps; i++) {
		x = x + xSpeed;
		y = y + ySpeed;

		mRegion.x = x;
		mRegion.y = y;

		setRegion(mRegion);
	}

    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //


