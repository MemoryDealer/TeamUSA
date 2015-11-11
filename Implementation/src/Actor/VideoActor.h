// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \ file VideoActor.h
/// \  This module makes sure An actor that will only display a texture at a given region. This actor will have no interation with the player.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"
namespace USA{
    class VideoActor
    {
        public:
        // Declare constructor and destructor...

        // Constructor.
            explicit VideoActor(Region region, int textureId  = -1, int layer = 1 );
        // Destructor.
        virtual ~VideoActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

        // Override onClick, onHover, and step, provide documentation.

        ///
        /// \brief <Give description of what actor does on click>
        virtual const ActorEvent onClick( Player& player ) override;

        ///
        /// \brief <Give description of what actor does on hover>
        virtual const ActorEvent onHover( Player& player ) override;

        /// \brief <Give description of what happens each frame to this actor>
        virtual const ActorEvent step( Player& player ) override;

        // Declare additional functions here as specified in UML diagram.

    };
}
