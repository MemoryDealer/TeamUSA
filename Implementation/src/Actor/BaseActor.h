// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file BaseActor.h
/// \brief Declares BaseActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "ActorEvent.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {
    
    class Player;
    struct Point;

    ///
    /// \class BaseActor
    /// \brief Abstract class which all actors must derive from.    
    class BaseActor
    {

    public:

        explicit BaseActor( void );

        virtual ~BaseActor( void ) = 0;

        ///
        /// \brief Called when the actor is clicked on.
        /// \param player The player in the scene.
        /// \return The ActorEvent to be handled by Engine when clicked on.
        virtual const ActorEvent onClick( Player& player );

        ///
        /// \brief Called when the actor is hovered over with the mouse.
        /// \param player The player in the scene.
        /// \return The ActorEvent to be handled by Engine when hovered over.
        virtual const ActorEvent onHover( Player& player );

        ///
        /// \brief Called each frame, each derived actor should handle this.
        /// \param player The player in the scene.
        /// \return Any ActorEvent that should be handled immediately by Engine.
        virtual const ActorEvent step( Player& player ) = 0;

        ///
        /// \brief Calculates if point is in bounds of actor's region.
        /// \param point The point to test.
        /// \return True if point is within actor's region.
        virtual const bool isInBounds( const Point& point );

    private:

        //region
        //video
        //audioID

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
