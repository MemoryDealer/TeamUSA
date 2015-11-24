// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file InventoryItemActor.cpp
/// \brief Implements InventoryItemActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "InventoryItemActor.h"

#include "Player/Player.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

InventoryItemActor::InventoryItemActor(Region region, const int item_ID, const int texture_ID, const int layer_s)
: BaseActor(region), itemID(item_ID), pickedUp( false )
{
    mVideo = new ActorVideo();
    mVideo -> layer = layer_s;
    mVideo -> textureID = texture_ID;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

InventoryItemActor::~InventoryItemActor(void)
{
    delete mVideo;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent InventoryItemActor::onHover( Player& player )
{
    if ( !pickedUp ) {
        player.setCursor( CursorStyle::CURSOR_SELECT );
    }

    return BaseActor::onHover( player );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent InventoryItemActor::onClick( Player& player )
{
    /*
    1. The actor will add an item to the player's
    inventory;
    2. set its TextureID to an invalid value;
    3. set its pickedUp status to true.
    */
    if (!pickedUp){
        player.addItem(itemID);
        pickedUp = true;
        mVideo->textureID = -1;
    }
    ActorEvent e;
    return e;
}

const ActorEvent InventoryItemActor::step( Player& player ){

    ActorEvent e;
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

