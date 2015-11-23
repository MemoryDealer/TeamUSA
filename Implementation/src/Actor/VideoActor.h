// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file VideoActor.h
/// \brief Declares the VideoActor class
/// This module makes sure An actor that will only display a texture at a given region. This actor will have no interation with the player.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"
namespace teamusa{

    ///
    /// \class VideoActor
    /// \brief Displays a texture in a region and performs no other behavior.
    class VideoActor : public BaseActor
    {
        public:
        // Declare constructor and destructor...

        // Constructor.
            explicit VideoActor(Region region, int textureId, int layer);
        // Destructor.
        virtual ~VideoActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

		///
		/// \brief Advances the actor one frame. 
		/// \param Player The player
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
        virtual const ActorEvent step( Player& player ) override;
    };
}
