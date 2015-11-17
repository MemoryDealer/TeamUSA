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
    /// \brief <Give brief description here>
    class InventoryItemActor : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit InventoryItemActor(Region region, const int itemID = -1, const int textureID = -1, const int layer = -1);

        // Destructor.
        virtual ~InventoryItemActor(void) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

        ///
        /// \brief <Give description of what actor does on click>
        virtual const ActorEvent onClick( Player& player ) override;

        virtual const ActorEvent step( Player& player ) override;

        // Declare additional functions here as specified in UML diagram.

    private:

        int itemID;
        bool pickedUp = false;

        // Declare any data members here as specified in UML diagram.

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
