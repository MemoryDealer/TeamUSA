// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedVideoActor.cpp
/// \brief Declares DelayedVideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
#include "DelayedVideoActor.h"

using namespace teamusa;

	DelayedVideoActor::DelayedVideoActor( Region region, int textureID, int delaysteps, int disappearStep, int layer ){
		//....
		delaySteps=disappearStep - delaysteps;
		textureId=textureID;
		currentStep =0;
		disappear = disappearStep;
        mVideo = new ActorVideo();
        mVideo->layer = layer;
	}

	DelayedVideoActor::~DelayedVideoActor( void ){
        delete mVideo;
        mVideo = nullptr;
	}


	const ActorEvent DelayedVideoActor::step( Player& player )
	{
	    // Handle per-frame updates...

	    ActorEvent e;
	    // Assign data...
	    currentStep++;

	    if(currentStep==delaySteps){
			mVideo->textureID = textureId;
	    }
		else if (currentStep == disappear){
			mVideo->textureID = -1;
		}

	    return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //




