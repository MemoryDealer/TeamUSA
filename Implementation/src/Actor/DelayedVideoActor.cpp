// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedVideoActor.cpp
/// \brief Declares DelayedVideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
#include "DelayedVideoActor.h"

using namespace teamusa;

	DelayedVideoActor::DelayedVideoActor( Region region, int textureID, int delaysteps, int disappearStep ){
		//....
		mVideo = new ActorVideo;
		mVideo->textureID = textureID;
		mVideo->layer = layer;

		delaySteps=disappearStep - delaysteps;
		textureId=textureID;
		currentStep =0;
		disappear = disappearStep;
	}

	DelayedVideoActor::~DelayedVideoActor( void ){
		//....
		delete mVideo;
	}


	const ActorEvent DelayedVideoActor::step(Player& player)
	{
		// Handle per-frame updates...

		ActorEvent e;
		// Assign data...
		currentStep++;

<<<<<<< HEAD
		if (currentStep == delaySteps) {
			mVideo->textureID = textureId;
		}
		else if (currentStep == disappear) {
			mVideo->textureID = -1;
=======
	    if(currentStep==delaySteps){
			mVideo.textureID = textureId;
	    }
		else if (currentStep == disappear){
			mVideo.textureID = -1;
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d
		}

		return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //




