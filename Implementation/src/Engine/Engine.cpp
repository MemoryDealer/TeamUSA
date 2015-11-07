// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Engine.cpp
/// \brief Implements Engine class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Engine.h"

#include "Actor/ExampleActor.h"
#include "Engine/Assert.h"
#include "Video/VideoEngine.hpp"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace USA;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#define BIND( function ) ( std::bind( function, this, std::placeholders::_1, std::placeholders::_2 ) )

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Engine::Engine( void )
: mVideoEngine( nullptr )
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
                                         720, 
                                         480 ) );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Engine::~Engine( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::run( void )
{
    mIsRunning = true;

    while ( mIsRunning ) {

    }
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Point Engine::getMouseCoordinates( void ) const
{

    return Point();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const int32_t Engine::getMouseClickState( void ) const
{

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::handleEvent( BaseActor& actor, const ActorEvent& e )
{
    // Call the actor event handler.
    Assert( static_cast<size_t>( e.type ) < mActorEventHandlers.size() );
    mActorEventHandlers[e.type] ( actor, e.value );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::render( void )
{

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

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onStreamAudio( BaseActor& actor, const int32_t value )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //