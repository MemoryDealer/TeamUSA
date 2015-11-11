// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Engine.h
/// \brief Declares Engine class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Headers.h"

#include "Point.hpp"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {

    // Forward declarations:

    struct ActorEvent;
    class AudioEngine;
    class BaseActor;
    class VideoEngine;

    // Function pointer type for handling actor events.
    typedef std::function< void( BaseActor& actor, const int32_t value ) > ActorEventHandler;

    ///
    /// \class Engine
    /// \brief Processes all components of the game each frame.
    class Engine final
    {

    public:

        explicit Engine( void );

        ~Engine( void );

        ///
        /// \brief Starts the game, runs until the player quits or there is an exception.
        void run( void );

    private:

        ///
        /// \brief Retrieves the window mouse coordinates.
        /// \return A Point struct containg the x and y values of the mouse.
        const Point getMouseCoordinates( void ) const;

        ///
        /// \brief Retrives the current mouse button state.
        /// \return Integer describing mouse state.
        const int32_t getMouseClickState( void ) const;

        ///
        /// \brief Handles actor event on actor who triggered it.
        /// \details Looks up function pointer in table, calls the corresponding function.
        void handleEvent( BaseActor& actor, const ActorEvent& e );

        ///
        /// \brief Renders all actors in the scene.
        void render( void );

        // All actor event handlers:

        void onChangeScene( BaseActor& actor, const int32_t value );
        void onLoadLevel( BaseActor& actor, const int32_t value );
        void onPlayAudio( BaseActor& actor, const int32_t value );
        void onNewGame( BaseActor& actor, const int32_t value );
        void onLoadGame( BaseActor& actor, const int32_t value );
        void onDisplayText( BaseActor& actor, const int32_t value );
        void onExitGame( BaseActor& actor, const int32_t value );
        void onStreamAudio( BaseActor& actor, const int32_t value );

    private:

        std::shared_ptr<AudioEngine> mAudioEngine;
        std::shared_ptr<VideoEngine> mVideoEngine;
        //Level mCurrentLevel;
        //Player mPlayer;
        bool mIsRunning;

        // Each index is an ActorEventType, associated with a handler function.
        std::vector<ActorEventHandler> mActorEventHandlers;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
