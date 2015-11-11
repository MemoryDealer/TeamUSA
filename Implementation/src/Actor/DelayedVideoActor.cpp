// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedVideoActor.cpp
/// \brief Declares DelayedVideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
#include "DelayedVideoActor.h"

using namespace teamusa;

	DelayedVideoActor::DelayedVideoActor( Region region, int textureID, int delaysteps, int disappearStep,int layer ){
		//....
		delaySteps=disappearStep - delaysteps;
		textureId=textureID;
		currentStep =0;
		disappear = -1;
	}

	DelayedVideoActor::~DelayedVideoActor( void ){
		//....
	}

	const ActorEvent DelayedVideoActor::onClick( Player& player )
	{
	    // Handle clicking logic...

	    ActorEvent e;
	    // Assign data...
	    return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

	const ActorEvent DelayedVideoActor::onHover( Player& player )
	{
	    // Handle hovering logic...

	    ActorEvent e;
	    // Assign data...
	    return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

	const ActorEvent DelayedVideoActor::step( Player& player )
	{
	    // Handle per-frame updates...

	    ActorEvent e;
	    // Assign data...
	    currentStep++;

	    if(currentStep==delaySteps){
	    	e.value=textureId;
	    	e.type= Nil;
	    }
	    else{
	    	e.value=-1;
	    }

	    return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //




