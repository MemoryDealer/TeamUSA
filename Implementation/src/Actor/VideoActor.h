// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file VideoActor.h
/// This module makes sure An actor that will only display a texture at a given region. This actor will have no interation with the player.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"
namespace teamusa{
    class VideoActor : public BaseActor
    {
        public:
        // Declare constructor and destructor...

        // Constructor.
            explicit VideoActor(Region region, int textureId, int layer);
        // Destructor.
        virtual ~VideoActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

        virtual const ActorEvent step( Player& player ) override;
    };
}
