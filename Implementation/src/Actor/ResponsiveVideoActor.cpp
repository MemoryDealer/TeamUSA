/*
 * ResponsiveVideoActor.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Juan Carmona
 */

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file ResponsiveVideoActor.cpp
/// \brief  Will display the default TextureID.
//  When onHover is called, it will display the hover TextureID.
//  When onClick is called, the onClick texture will be set permanently.
//  Can disappear or appear by utilizing an invalid TextureID.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "ResponsiveVideoActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveVideoActor::ResponsiveVideoActor( Region region, int hoverTextureId, int clickTextureID, int defaulTextureID,int layer )
{
    // ...
	hoverTexture = hoverTextureId;
	clickTexture = clickTextureID;
	
	mVideo = new ActorVideo;
	mVideo->textureID = defaulTextureID;
	mVideo->layer = layer;


}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveVideoActor::~ResponsiveVideoActor( void )
{
    // ...
	delete mVideo;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveVideoActor::onClick( Player& player )
{
    // Handle clicking logic...

    ActorEvent e;
    // Assign data...
<<<<<<< HEAD
	mVideo->textureID = clickTexture;
=======
	mVideo.textureID =clickTexture;
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveVideoActor::onHover(Player& player)
{
	// Handle hovering logic...

<<<<<<< HEAD
	ActorEvent e;
	// Assign data...

	if (mVideo->textureID != clickTexture) {
		mVideo->textureID = hoverTexture;
	}
=======
    ActorEvent e;
    // Assign data...
	mVideo.textureID = hoverTexture;
	
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d


	return e;
}

<<<<<<< HEAD
const ActorEvent ResponsiveVideoActor::step(Player& player)
=======
const ActorEvent ResponsiveVideoActor::step()
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d
{
	// Handle per-frame updates...

	ActorEvent e;
	// Assign data...
<<<<<<< HEAD
	if (mVideo->textureID != clickTexture) {
		mVideo->textureID = defaultTextureId;
	}
=======
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d

	return e;
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void ResponsiveVideoActor::setTextureId(int TextureId){
<<<<<<< HEAD
	mVideo->textureID = TextureId;
=======
	mVideo.textureID=TextureId;
>>>>>>> e2ea63cbc3779777808a7eae2ee791b7d7112f9d
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

