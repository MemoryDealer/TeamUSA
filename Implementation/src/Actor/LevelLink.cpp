// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file LevelLink.cpp
/// \brief Implements LevelLink class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "LevelLink.h"

#include "Player/Player.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

LevelLink::LevelLink(Region region, const int Level_ID, const int sceneID, const std::string itemRequired_Text, const int item_ID)
: BaseActor(region), sceneID(sceneID), levelID(Level_ID), itemRequiredText(itemRequired_Text), requiredItemID(item_ID)
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

LevelLink::~LevelLink(void)
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent LevelLink::onClick( Player& player )
{
    // Handle clicking logic...
    /*
    Will emit a LoadLevel event with the value of the level to load when onClick is called if the player has the
    specified item in its inventory.
    If the item id is invalid, then the check is not enforced.
    */

    ActorEvent e;

    if( requiredItemID != -1){
        if (player.hasItem( requiredItemID ) == true){
            e.type = LoadLevel;         //change the senece when have keys
            e.value = levelID;          //
        }
        else{
            //check if player does not have item.
			e.type = DisplayText;
        }
    }
    else{
        e.type = LoadLevel;
        e.value = levelID;
    }


    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent LevelLink::onHover( Player& player )
{
    player.setCursor( CursorStyle::CURSOR_UP );

    return BaseActor::onHover( player );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const int LevelLink::getSceneID() const
{
    return sceneID;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const std::string LevelLink::getText()
{

    return itemRequiredText;

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent LevelLink::step( Player& player )
{
    ActorEvent e;
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
