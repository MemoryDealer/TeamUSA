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

		///
		/// \brief Handles scene change events triggered by SceneLink actors.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onChangeScene( BaseActorPtr actor, const int32_t value );

		///
		/// \brief Handles level change events triggered by LevelLink actors.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onLoadLevel( BaseActorPtr actor, const int32_t value );

		///
		/// \brief Handles audio events triggered by actors. Calls into the AudioEngine.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onPlayAudio( BaseActorPtr actor, const int32_t value );

		///
		/// \brief Handles new game events triggered by main menu actors.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onNewGame( BaseActorPtr actor, const int32_t value );

		/// 
		/// \brief Handles load game events triggered by main menu actors.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onLoadGame( BaseActorPtr actor, const int32_t value );

		///
		/// \brief Handles text display events triggered by actors.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onDisplayText( BaseActorPtr actor, const int32_t value );

		///
		/// \brief Handles exit game events triggered by quit game button at main menu.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onExitGame( BaseActorPtr actor, const int32_t value );

		///
		/// \brief Handles stream audio events triggered by actors, calls into AudioEngine.
		/// \param actor The actor who triggered the event.
		/// \param value A value corresponding to the event, if needed.
        void onStreamAudio( BaseActorPtr actor, const int32_t value );

		///
        /// \brief Clears resource data for current level and loads the specified level.
        void freeAndLoadLevel( const int32_t id );

    private:

        // Function pointer type for handling actor events.
        typedef std::function< void( BaseActorPtr actor, const int32_t value ) > ActorEventHandler;

    private:

        std::shared_ptr<AudioEngine> mAudioEngine;
        std::shared_ptr<VideoEngine> mVideoEngine;
        Level mLevel;
        int32_t mCurrentLevelID;
        Player mPlayer;
        bool mIsRunning, mMainMenu;
        GameSaveSerializer mSerializer;

        // Each index is an ActorEventType, associated with a handler function.
        std::vector<ActorEventHandler> mActorEventHandlers;

#ifdef DEBUG_TOOLS
        struct {
            bool drawDebugBoxes = false;
            bool disableLighting = false;
            std::stack<int> scenes;
        } mDebugData;
#endif

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
