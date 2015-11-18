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
    /// \class TextboxSpawnActor
    /// \brief <Give brief description here>
    class LevelLink : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit LevelLink(Region region, const int Level_ID, const int sceneID, const std::string itemRequired_Text, const int item_ID = -1);

        // Destructor.
        virtual ~LevelLink(void) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

        // Override onClick, onHover, and step, provide documentation.

        ///
        /// \brief <Give description of what actor does on click>
        virtual const ActorEvent onClick( Player& player ) override;

        virtual const ActorEvent step( Player& player ) override;

        const int getSceneID( void ) const;

        virtual const std::string getText();

    private:

        int sceneID;
        int levelID;
        std::string itemRequiredText;
        int requiredItemID = -1;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
