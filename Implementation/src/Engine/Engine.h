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

#include "Engine/Level.h"
#include "GameSaveSerializer/GameSaveSerializer.h"
#include "Player/Player.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {

    // Forward declarations:

    struct ActorEvent;
    class AudioEngine;
    class BaseActor;
    class VideoEngine;    

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
        void handleEvent( BaseActorPtr actor, const ActorEvent& e );

        ///
        /// \brief Renders all actors in the scene.
        void render( const ActorList& actors );

        // All actor event handlers:

        void onChangeScene( BaseActorPtr actor, const int32_t value );
        void onLoadLevel( BaseActorPtr actor, const int32_t value );
        void onPlayAudio( BaseActorPtr actor, const int32_t value );
        void onNewGame( BaseActorPtr actor, const int32_t value );
        void onLoadGame( BaseActorPtr actor, const int32_t value );
        void onDisplayText( BaseActorPtr actor, const int32_t value );
        void onExitGame( BaseActorPtr actor, const int32_t value );
        void onStreamAudio( BaseActorPtr actor, const int32_t value );

        // Clears resource data for current level and loads the specified level.
        void freeAndLoadLevel( const int32_t id );

    private:

        // Function pointer type for handling actor events.
        typedef std::function< void( BaseActorPtr actor, const int32_t value ) > ActorEventHandler;

    private:

        std::shared_ptr<AudioEngine> mAudioEngine;
        std::shared_ptr<VideoEngine> mVideoEngine;
        Level mLevel;
        Player mPlayer;
        bool mIsRunning;
        GameSaveSerializer mSerializer;

        // Each index is an ActorEventType, associated with a handler function.
        std::vector<ActorEventHandler> mActorEventHandlers;

#ifdef _DEBUG
        struct {
            bool drawDebugBoxes = false;
            bool disableLighting = false;
            std::stack<int> scenes;
        } mDebugData;
#endif

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
