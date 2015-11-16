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
	defaultTextureId = defaulTextureID;

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

ResponsiveVideoActor::~ResponsiveVideoActor( void )
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveVideoActor::onClick( Player& player )
{
    // Handle clicking logic...

    ActorEvent e;
    // Assign data...
	mVideo.textureID =clickTexture;
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent ResponsiveVideoActor::onHover( Player& player )
{
    // Handle hovering logic...

    ActorEvent e;
    // Assign data...
	mVideo.textureID = hoverTexture;
	

    return e;
}

const ActorEvent ResponsiveVideoActor::step( Player& player )
{
	// Handle per-frame updates...

	ActorEvent e;
	// Assign data...

	return e;
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void ResponsiveVideoActor::setTextureId(int TextureId){
	mVideo.textureID=TextureId;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

