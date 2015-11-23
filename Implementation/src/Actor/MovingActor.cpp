// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file MovingActor.cpp
/// \brief Implements the MovingActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "MovingActor.h"

#include "Player/Player.h"

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

	hGrowth = (endRegion.h - startRegion.h) / transitionSteps;
	wGrowth = (endRegion.w - startRegion.w) / transitionSteps;
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
	delete mVideo;
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

const ActorEvent MovingActor::onHover( Player& player )
{
    if ( !isActive ) {
        player.setCursor( CursorStyle::CURSOR_SELECT );
    }

    return BaseActor::onHover( player );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent MovingActor::step( Player& player )
{
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
	return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //


