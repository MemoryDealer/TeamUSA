// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Engine.cpp
/// \brief Implements Engine class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Engine.h"

#include "Actor/ExampleActor.h"
#include "Audio/AudioEngine.hpp"
#include "Engine/Assert.h"
#include "Engine/ResourceGroup.hpp"
#include "Video/VideoEngine.hpp"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// Creates function pointer with two parameters.
#define BIND( function ) ( std::bind( function, this, std::placeholders::_1, std::placeholders::_2 ) )

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Engine::Engine( void )
: mAudioEngine( nullptr )
, mVideoEngine( nullptr )
, mIsRunning( false )
, mActorEventHandlers( )
{
    // Register actor event handlers.
    mActorEventHandlers.push_back( BIND( &Engine::onChangeScene ) );
    mActorEventHandlers.push_back( BIND( &Engine::onLoadLevel ) );
    mActorEventHandlers.push_back( BIND( &Engine::onPlayAudio ) );
    mActorEventHandlers.push_back( BIND( &Engine::onNewGame ) );
    mActorEventHandlers.push_back( BIND( &Engine::onLoadGame ) );
    mActorEventHandlers.push_back( BIND( &Engine::onDisplayText ) );
    mActorEventHandlers.push_back( BIND( &Engine::onExitGame ) );
    mActorEventHandlers.push_back( BIND( &Engine::onStreamAudio ) );

    mVideoEngine.reset( new VideoEngine( "LEGEND OF THE GREAT UNWASHED", 
                                         1280, 
                                         720 ) );
    mAudioEngine.reset( new AudioEngine() );

    // Load main menu level...
    // ...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Engine::~Engine( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::run( void )
{
    mIsRunning = true;

    mVideoEngine->showTextbox( "LEGEND OF THE GREAT UNWASHED" );

    while ( mIsRunning ) {

        // TODO: Add frame rate independence (requires Timer).

        // Iterate over all actors in current scene.
        ActorList actors; // = mLevel.getActiveScene().getShit();
        for ( auto& actor : actors ) {
            ActorEvent e;

            // Test mouse hover.
            if ( actor.isInBounds( mPlayer.getPosition() ) ) {
                e = actor.onHover( mPlayer );
                handleEvent( actor, e );

                // Test mouse click.
                if ( getMouseClickState() ) {
                    e = actor.onClick( mPlayer );
                    handleEvent( actor, e );
                }
            }

            // Update the actor.
            e = actor.step( mPlayer );
            handleEvent( actor, e );
        }

        // Update player.
        mPlayer.setPosition( getMouseCoordinates() );

        // Update SDL.
        SDL_Event e;
        while ( SDL_PollEvent( &e ) ) {
            switch ( e.type ) {
            default:
                break;

            case SDL_QUIT:
                mIsRunning = false;
                break;
            }
        }
        
        // Render the current scene.
        render( actors );
    }
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Point Engine::getMouseCoordinates( void ) const
{
    Point point( 0, 0 );

    SDL_GetMouseState( &point.x, &point.y );

    return point;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const int32_t Engine::getMouseClickState( void ) const
{
    // Return true on left button down.
    return ( 
        SDL_GetMouseState( nullptr, nullptr ) & SDL_BUTTON( SDL_BUTTON_LEFT ) );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::handleEvent( BaseActor& actor, const ActorEvent& e )
{
    // Call the actor event handler.
    Assert( static_cast<size_t>( e.type ) < mActorEventHandlers.size() );
    mActorEventHandlers[e.type] ( actor, e.value );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::render( const ActorList& actors )
{
    for ( auto& actor : actors ) {
        mVideoEngine->render( actor.getRegion(), 
                              actor.getLayer(), 
                              actor.getTextureID() );
    }

    mVideoEngine->display();

    SDL_Delay( 17 );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// Actor event handlers:

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onChangeScene( BaseActor& actor, const int32_t value )
{
    
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onLoadLevel( BaseActor& actor, const int32_t value )
{
    mVideoEngine->deleteResourceGroup( LEVEL_RESOURCE );
    
    // Load the level...
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onPlayAudio( BaseActor& actor, const int32_t value )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onNewGame( BaseActor& actor, const int32_t value )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onLoadGame( BaseActor& actor, const int32_t value )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onDisplayText( BaseActor& actor, const int32_t value )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onExitGame( BaseActor& actor, const int32_t value )
{
    mIsRunning = false;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onStreamAudio( BaseActor& actor, const int32_t value )
{
    
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
