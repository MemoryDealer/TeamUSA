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
    /// \class TextboxSpawnActor
    /// \brief <Give brief description here>
    class SceneLink : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit SceneLink(Region region, const int scene_ID, const std::string &itemRequired_Text, const int item_ID = -1);

        // Destructor.
        virtual ~SceneLink(void) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

        ///
        /// \brief <Give description of what actor does on click>
        virtual const ActorEvent onClick( Player& player ) override;

        virtual const ActorEvent onHover( Player& player ) override;

        virtual const ActorEvent step( Player& player ) override;

        virtual const std::string getText();

    private:

        int sceneID;
        std::string itemRequiredText;
        int requiredItemID;
        CursorStyle cursorStyle;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
