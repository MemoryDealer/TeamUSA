// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file LevelLink.h
/// \brief Declares LevelLink class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa {

    // Create new Actor and derive from BaseActor.
    // Provide documentation, do so by starting with "///"
    ///
    /// \class LevelLink
    /// \brief Allows the player to transition between levels.
    class LevelLink : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit LevelLink(Region region, const int Level_ID, const int sceneID, const std::string itemRequired_Text, const int item_ID = -1);

        // Destructor.
        virtual ~LevelLink(void) override; 

        ///
        /// \brief Returns an actor event when the actor's region is clicked on. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
        virtual const ActorEvent onClick( Player& player ) override;
		
		///
		/// \brief Returns an actor event when the actor's region is hovered over. 
		/// \param Player The player. 
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent onHover( Player& player ) override;

		///
		/// \brief Advances the actor one frame. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent step( Player& player ) override;

		///
		/// \brief Gets the appropriate SceneID
		/// \return Returns an integer representing the scene ID. 
        const int getSceneID( void ) const;

		///
		/// \brief Generates text when the player attempts to traverse a scene without a required item
        virtual const std::string getText();

    private:

        int sceneID;
        int levelID;
        std::string itemRequiredText;
        int requiredItemID = -1;
    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
