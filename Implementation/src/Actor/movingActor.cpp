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
	mVideo = new ActorVideo;
	mVideo->textureID = textureId;
	mVideo->layer = layer;

	endRegion=endregion;
	mRegion = startRegion;

	hGrowth = (endRegion.h - startRegion.h) / transitionSteps;;
	wGrowth = (endRegion.w - startRegion.w) / transitionSteps;;
	transitionSteps = transitionsteps;
	currentStep = 0;
	xSpeed = (endRegion.x - startRegion.x) / transitionSteps;
	ySpeed = (endRegion.y - startRegion.y) / transitionSteps;
<<<<<<< HEAD
	isActive = moveOnSpawn;
=======
	isActive = moveOnSpawn;	
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

MovingActor::~MovingActor( void )
{
    // ...
	delete mVideo;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent MovingActor::onClick( Player& player )
{
    // Handle clicking logic...

    ActorEvent e;
    // Assign data...
	isActive = true;
<<<<<<< HEAD
	
=======


>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent MovingActor::step()
{
<<<<<<< HEAD
	// Handle per-frame updates...

	ActorEvent e;
	// Assign data...

	if (isActive) {
		if( currentStep < transitionSteps) {
			mRegion.x += xSpeed;
			mRegion.y += ySpeed;
			mRegion.h += hGrowth;
			mRegion.w += wGrowth;

			currentStep++;
		}
	}
=======
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
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d

	return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //


