// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file SceneLink.cpp
/// \brief Implements SceneLink class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "SceneLink.h"

#include "Player/Player.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

SceneLink::SceneLink( Region region, const int scene_ID, const std::string &itemRequired_Text, const int item_ID )
: BaseActor(region), sceneID(scene_ID), itemRequiredText(itemRequired_Text), requiredItemID(item_ID)
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

SceneLink::~SceneLink(void)
{
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent SceneLink::onClick( Player& player )
{
    // Handle clicking logic...
    /*
    Will emit a LoadLevel event with the value of the level to load when onClick is called if the player has the
    specified item in its inventory.
    If the item id is invalid, then the check is not enforced.
    */

    ActorEvent e;

    if( requiredItemID != -1){
        if ( player.hasItem( requiredItemID ) ){
            e.type = ChangeScene;         //change the senece when have keys
            e.value = sceneID;          //
        }
        else{
            //check if player does not have item.

        }
    }
    else{
        e.type = ChangeScene;
        e.value = sceneID;
    }


    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent SceneLink::step( Player& player )
{
    ActorEvent e;
    return e;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

/*const int LevelLink::getSceneID()
{
    return SceneID;
}*/

const std::string SceneLink::getText()
{

    return itemRequiredText;

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
