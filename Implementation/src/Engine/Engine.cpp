// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Engine.cpp
/// \brief Implements Engine class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Engine.h"

#include "Actor/AudioStreamActor.h"
#include "Actor/SceneLink.h"
#include "Actor/TextboxSpawnActor.h"
#include "Audio/AudioEngine.hpp"
#include "Engine/Assert.h"
#include "Engine/ResourceGroup.hpp"
#include "Engine/Timer.h"
#include "Video/VideoEngine.hpp"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// Creates function pointer with two parameters.
#define BIND( function ) ( std::bind( function, this, std::placeholders::_1, std::placeholders::_2 ) )

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const static double FRAME_TIME = 16.67;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Engine::Engine( void )
: mAudioEngine( nullptr )
, mVideoEngine( nullptr )
, mLevel()
, mIsRunning( false )
, mActorEventHandlers( )
#ifdef _DEBUG
, mDebugData()
#endif
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
                                         853 ) );
    mAudioEngine.reset( new AudioEngine() );

    // Load core resources.
    mVideoEngine->loadTexture( "res/images/Cursor/Light.png", 
                               Player::FLASHLIGHT_ID,
                               CORE_RESOURCE );
    mVideoEngine->loadTexture( "res/images/Cursor/Default.png",
                               Player::CURSOR_DEFAULT_ID,
                               CORE_RESOURCE );
    mVideoEngine->loadTexture( "res/images/Cursor/Select.png",
                               Player::CURSOR_SELECT_ID,
                               CORE_RESOURCE );
    mVideoEngine->loadTexture( "res/images/Cursor/Up.png",
                               Player::CURSOR_UP_ID,
                               CORE_RESOURCE );
    mVideoEngine->loadTexture( "res/images/Cursor/Down.png",
                               Player::CURSOR_DOWN_ID,
                               CORE_RESOURCE );
    mVideoEngine->loadTexture( "res/images/Cursor/Left.png",
                               Player::CURSOR_LEFT_ID,
                               CORE_RESOURCE );
    mVideoEngine->loadTexture( "res/images/Cursor/Right.png",
                               Player::CURSOR_RIGHT_ID,
                               CORE_RESOURCE );
    SDL_ShowCursor( false );

    mAudioEngine->loadSound( "res/audio/SoundEffects/MouseClick.wav",
                             Player::MOUSE_CLICK_ID,
                             CORE_RESOURCE );

    // Load main menu level...
    //...
    mLevel.loadLevel( "res/lvl/1.lvl", *mAudioEngine, *mVideoEngine );

#ifdef _DEBUG
    mDebugData.scenes.push(mLevel.getScene());
#endif
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Engine::~Engine( void )
{
    mVideoEngine->deleteResourceGroup( LEVEL_RESOURCE );
    mVideoEngine->deleteResourceGroup( CORE_RESOURCE );
    mAudioEngine->deleteSoundGroup( LEVEL_RESOURCE );
    mAudioEngine->deleteSoundGroup( CORE_RESOURCE );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::run( void )
{
    mIsRunning = true;

    Timer timer;
    timer.start();    
    double prev = timer.getTicks();
    double lag = 0.0;

    while ( mIsRunning ) {

        mPlayer.setCursor( CursorStyle::CURSOR_DEFAULT );
       
        // Calculate elapsed time since last frame.
        double current = timer.getTicks();
        double elapsed = current - prev;
        prev = current;
        lag += elapsed;

        // Get all actors in current scene.
        ActorList actors = mLevel.getActors();

        // Update game logic. May be updated multiple times per frame if there
        // is a hitch in the system, for instance. This will produce frame rate
        // independent animations.
        while ( lag >= FRAME_TIME ) {
            // Iterate over all actors in current scene.            
            for ( auto& actor : actors ) {
                ActorEvent e;

                // Update the actor.
                e = actor->step( mPlayer );
                handleEvent( actor, e );

                // Test mouse hover.
                if ( actor->isInBounds( mPlayer.getPosition() ) ) {
                    e = actor->onHover( mPlayer );
                    handleEvent( actor, e );
                }
            }

            // Update SDL.
            SDL_Event e;
            while ( SDL_PollEvent( &e ) ) {
                switch ( e.type ) {
                default:
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if ( mVideoEngine->isShowingTextbox() ) {
                        mVideoEngine->hideTextbox();
                    }
                    else {
                        for ( auto& actor : actors ) {
                            if ( actor->isInBounds( mPlayer.getPosition() ) ) {
                                ActorEvent e = actor->onClick( mPlayer );
                                
                                // Play the mouse click sound effect if no sound is 
                                // being triggered.
                                if ( e.type != ActorEventType::PlayAudio ) {
                                    mAudioEngine->playSound( Player::MOUSE_CLICK_ID );
                                }

                                handleEvent( actor, e );                                
                            }
                        }
                    }                    
                    break;

#ifdef _DEBUG
                case SDL_KEYDOWN:
                    switch ( e.key.keysym.sym ) {
                    default:
                        break;

                    case SDLK_d:
                        mDebugData.drawDebugBoxes = !mDebugData.drawDebugBoxes;
                        break;

                    case SDLK_l:
                        mDebugData.disableLighting = !mDebugData.disableLighting;
                        break;

                    case SDLK_r:
                    {
                        // Reload all current level assets and remain in the same scene.
                        // Useful for editing click regions.
                        int currentScene = mLevel.getScene();
                        mVideoEngine->deleteResourceGroup( LEVEL_RESOURCE );
                        mAudioEngine->deleteSoundGroup( LEVEL_RESOURCE );
                        mLevel.reloadLast( *mAudioEngine, *mVideoEngine );
                        mLevel.changeScene( currentScene );
                    }
                    break;

                    case SDLK_1:
                        freeAndLoadLevel( 1 );
                        break;

                    case SDLK_2:
                        freeAndLoadLevel( 2 );
                        break;

                    case SDLK_3:
                        freeAndLoadLevel( 3 );
                        break;

                    case SDLK_4:
                        freeAndLoadLevel( 4 );
                        break;

                    case SDLK_BACKSPACE:
                        if ( mDebugData.scenes.size() > 1 ) {
                            mDebugData.scenes.pop();
                            if ( !mDebugData.scenes.empty() ) {
                                mLevel.changeScene( mDebugData.scenes.top() );
                            }
                        }
                        break;

                    case SDLK_END:
                        mIsRunning = false;
                        break;
                    }
                    break;
#endif

                case SDL_QUIT:
                    mIsRunning = false;
                    break;
                }
            }

            // Update player.
            mPlayer.setPosition( getMouseCoordinates() );

            // Decrement the ms left for this frame time.
            lag -= FRAME_TIME;
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

void Engine::handleEvent( BaseActorPtr actor, const ActorEvent& e )
{
    if ( e.type == ActorEventType::Nil ) {
        return;
    }

    // Call the actor event handler.
    Assert( static_cast<size_t>( e.type ) < mActorEventHandlers.size() );
    mActorEventHandlers[e.type] ( actor, e.value );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::render( const ActorList& actors )
{
    // Render background image first.
    Region bg { 0, 0, 1280, 853 };
#ifdef _DEBUG
    if ( mDebugData.disableLighting ) {
        mVideoEngine->render( bg, 6, mLevel.getBGImageID() );
    }
    else {
        mVideoEngine->render( bg, 0, mLevel.getBGImageID() );
    }
#else
    mVideoEngine->render( bg, 0, mLevel.getBGImageID() );    
#endif

    Point p = getMouseCoordinates();
    // Render player cursor.
    Region cursor { p.x - 16, p.y - 16, 32, 32 };
    mVideoEngine->render( cursor, 6, mPlayer.getCursorTextureID() );    

    // Render player flashlight.
    Region f { p.x - 256, p.y - 256, 512, 512 };
    mVideoEngine->render( f, 4, Player::FLASHLIGHT_ID );

    // Render all actors with textures in current scene.
    for ( auto& actor : actors ) {
        if ( actor->hasVideo() ) {
            if ( actor->getTextureID() != -1 ) {
                mVideoEngine->render( actor->getRegion(),
                                      actor->getLayer(),
                                      actor->getTextureID() );
            }
        }

#ifdef _DEBUG
        if ( mDebugData.drawDebugBoxes ) {            
            mVideoEngine->renderDebugBox( actor->getRegion() );            
        }
#endif
    }

    mVideoEngine->display();

    SDL_Delay( static_cast<uint32_t>( FRAME_TIME ) );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// Actor event handlers:

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onChangeScene( BaseActorPtr actor, const int32_t value )
{    
    mLevel.changeScene( value );    

#ifdef _DEBUG
    mDebugData.scenes.push( value );
#endif
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onLoadLevel( BaseActorPtr actor, const int32_t value )
{
    freeAndLoadLevel( value );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onPlayAudio( BaseActorPtr actor, const int32_t value )
{
    mAudioEngine->playSound( value );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onNewGame( BaseActorPtr actor, const int32_t value )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onLoadGame( BaseActorPtr actor, const int32_t value )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onDisplayText( BaseActorPtr actor, const int32_t value )
{

	std::string text = ".";
	if ( typeid( *actor ) == typeid( SceneLink ) ) {
		text = "Item required: " + std::dynamic_pointer_cast<SceneLink>(actor)->getText();
	}
	else if ( typeid( *actor ) == typeid( TextboxSpawnActor ) ) {
		text = std::dynamic_pointer_cast<TextboxSpawnActor>(actor)->getText();
	}        

    mVideoEngine->showTextbox( text );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onExitGame( BaseActorPtr actor, const int32_t value )
{
    mIsRunning = false;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onStreamAudio( BaseActorPtr actor, const int32_t value )
{
    // Downcast BaseActor smart pointer to AudioStreamActor smart pointer.
    std::string path = 
        std::dynamic_pointer_cast<AudioStreamActor>( actor )->getPath();

    mAudioEngine->playStream( path );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::freeAndLoadLevel( const int32_t id )
{
    mVideoEngine->deleteResourceGroup( LEVEL_RESOURCE );
    mAudioEngine->deleteSoundGroup( LEVEL_RESOURCE );
    mLevel.loadLevel( "res/lvl/" + std::to_string( id ) + ".lvl",
                      *mAudioEngine,
                      *mVideoEngine );

#ifdef _DEBUG
    while ( !mDebugData.scenes.empty() ) {
        mDebugData.scenes.pop();
    }
    mDebugData.scenes.push( mLevel.getScene() );
#endif
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
