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
#include "Audio/AudioEngine.hpp"
#include "Video/VideoEngine.hpp"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {
	
	///
	/// \class ActorVideo
	/// \brief Contains data for rendering actor.
    struct ActorVideo {
        int32_t layer;
        int32_t textureID;

        ActorVideo( void ) : layer( -1 ), textureID( -1 ) { }
    };

    // ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
        
    class Player;
    struct Point;

    ///
    /// \class BaseActor
    /// \brief Abstract class which all actors must derive from.    
    class BaseActor
    {

    public:

        explicit BaseActor( const Region& region = Region() );

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

        ///
        /// \brief Sets the actor's region (can be used by Level when loading).
        /// \param region The Region to set.
        virtual void setRegion( const Region& region );

        ///
        /// \brief Gets the actor's Region.
        /// \return The actor's Region struct.
        virtual const Region getRegion( void ) const;

        ///
        /// \brief Gets the layer the actor should be rendered on.
        /// \return An integer containing the layer.
        virtual const int32_t getLayer( void ) const;

        ///
        /// \brief Gets the texture ID of the actor.
        /// \return The integer containing the texture ID.
        virtual const int32_t getTextureID( void ) const;

        ///
        /// \brief Returns true if the actor has a video component.
        const bool hasVideo( void ) const;

    protected:

        Region mRegion;
        AudioID mAudioID;
		ActorVideo *mVideo;
    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
