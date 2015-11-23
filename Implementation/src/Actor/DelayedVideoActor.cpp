// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedVideoActor.cpp
/// \brief Implements the DelayedVideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
#include "DelayedVideoActor.h"

#include <iostream>
using namespace teamusa;

	DelayedVideoActor::DelayedVideoActor( Region region, int textureID, int delaysteps, int disappearStep, int layer )
    : BaseActor() 
  {
		//....
		mVideo = new ActorVideo;
		mVideo->textureID = -1;
		mVideo->layer = layer;

    this->mRegion = region;
		this->delaySteps = delaysteps;
		this->disappear = disappearStep;
		this->textureId=textureID;
		this->currentStep = 0;
    
	}

	DelayedVideoActor::~DelayedVideoActor( void ){
    delete mVideo;
	}


	const ActorEvent DelayedVideoActor::step(Player& player)
	{
		// Handle per-frame updates...

		ActorEvent e;
		// Assign data...
    if(currentStep==delaySteps){
			mVideo->textureID = textureId;
    }
		else if (currentStep == disappear){
			mVideo->textureID = -1;
		}
		currentStep++;

		return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //




