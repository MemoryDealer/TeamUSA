// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file VideoEventActor.cpp
/// \brief declares VideoEventActor class
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "VideoEventActor.h"
#include "Player/Player.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

VideoEventActor::VideoEventActor( Region region, int textureID,ActorEventType eventType, int eventValue, int layer )
{
	mVideo = new ActorVideo;
	mVideo->textureID = textureID;
	mVideo->layer = layer;

	actorEvent.type= eventType;
	actorEvent.value= eventValue;

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

VideoEventActor::~VideoEventActor( void )
{
	delete mVideo;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent VideoEventActor::onClick( Player& player )
{
    // Handle clicking logic...

    // Assign data...
    return actorEvent;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent VideoEventActor::step()
{
	// Handle per-frame updates...

	ActorEvent e;
	// Assign data...

	return e;
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent VideoEventActor::onHover( Player& player )
{
    // Handle hovering logic...

    ActorEvent e;
	e.type = ActorEventType::Nil;

    // Assign data...

	//how to do this?
    player.setCursor(CursorStyle::CURSOR_SELECT);

    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
