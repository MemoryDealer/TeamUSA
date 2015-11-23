// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file InventoryItemActor.h
/// \brief Declares InventoryItemActor class.
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
    /// \class InventoryItemActor
    /// \brief IventoryItemActor creates a collectible item in the game environment. 
    class InventoryItemActor : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit InventoryItemActor(Region region, const int itemID = -1, const int textureID = -1, const int layer = -1);

        // Destructor.
        virtual ~InventoryItemActor(void) override; 

		///
		/// \brief Generates an ActorEvent if the player hovers over the actors' region. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
        virtual const ActorEvent onHover( Player& player ) override;

        ///
        /// \brief Generates an ActorEvent if the player clicks in the actor's region. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
        virtual const ActorEvent onClick( Player& player ) override;
		
		///
		/// \brief Advances the actor one frame and sends the appropriate ActorEvent
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent step( Player& player ) override;

    private:

        int itemID;
        bool pickedUp = false;

        // Declare any data members here as specified in UML diagram.

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
