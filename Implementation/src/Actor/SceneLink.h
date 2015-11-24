// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file SceneLink.h
/// \brief Declares SceneLink class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

#include "Player/CursorStyle.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa {

    // Create new Actor and derive from BaseActor.
    // Provide documentation, do so by starting with "///"
    ///
    /// \class SceneLink
    /// \brief Allows the player to transition between scenes.
    class SceneLink : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit SceneLink(Region region, const int scene_ID, const std::string &itemRequired_Text, const int item_ID = -1);

        // Destructor.
        virtual ~SceneLink(void) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

		///
		/// \brief Generates an ActorEvent when the actor's region is clicked. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent onClick( Player& player ) override;

		///
        /// \brief Generates an ActorEvent when the actor's region is hovered over. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent onHover( Player& player ) override;

		///
		/// \brief Advances the actor one frame. 
		/// \param Player The player
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent step( Player& player ) override;

		///
		/// \brief Displays the appropriate text when a player attempts to traverse a scene without the required item. 
        virtual const std::string getText();

    private:

        int sceneID;
        std::string itemRequiredText;
        int requiredItemID;
        CursorStyle cursorStyle;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
