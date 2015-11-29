// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Engine.cpp
/// \brief Implements Engine class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Engine.h"

#include "Actor/AudioStreamActor.h"
#include "Actor/LevelLink.h"
#include "Actor/SceneLink.h"
#include "Actor/TextboxSpawnActor.h"
#include "Actor/VideoActor.h"
#include "Audio/AudioEngine.hpp"
#include "Engine/Assert.h"
#include "Engine/ResourceGroup.hpp"
#include "Engine/Timer.h"
#include "Video/VideoEngine.hpp"

#if defined ( _WIN32 )
#include <Windows.h>
#elif defined ( LINUX ) || defined( __APPLE__ )
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

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
, mCurrentLevelID( 0 )
, mIsRunning( false )
, mMainMenu( true )
, mSerializer()
, mActorEventHandlers()
#ifdef DEBUG_TOOLS
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

    // Load main menu level.
    mLevel.loadLevel( "res/lvl/0.lvl", *mAudioEngine, *mVideoEngine );

#ifdef DEBUG_TOOLS
    mDebugData.scenes.push(mLevel.getScene());
#endif

    // Create the saves directory.
#if defined( _WIN32 )
    CreateDirectory( "saves", nullptr );
#elif defined ( LINUX ) || defined( __APPLE__ )
    mkdir( "saves", 0700 );
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
        // Calculate elapsed time since last frame.
        double current = timer.getTicks();
        double elapsed = current - prev;
        prev = current;
        lag += elapsed;

        // Get all actors in current scene.
        ActorList actors = mLevel.getActors();

        // Move the background video actor for only the main menu.
        if ( mMainMenu ) {
			// Only move background every 3 frames to slow it down.
			static int inc = 0;
            // The background is always the first actor.
            Region r = actors[0]->getRegion();
            static bool xDir = true, yDir = false;
			if ( ++inc >= 3 ) {
				if ( xDir ) {
					if ( --r.x <= -1000 ) {
						xDir = false;
					}
				}
				else {
					if ( ++r.x >= 0 ) {
						xDir = true;
					}
				}
				if ( yDir ) {
					if ( ++r.y >= 0 ) {
						yDir = false;
					}
				}
				else {
					if ( --r.y <= -1000 ) {
						yDir = true;
					}
				}

				inc = 0;
			}

            actors[0]->setRegion( r );
        }

        // Update game logic. May be updated multiple times per frame if there
        // is a hitch in the system, for instance. This will produce frame rate
        // independent animations.
        bool clickSoundPlayed = false;
        while ( lag >= FRAME_TIME ) {

			mPlayer.setCursor( CursorStyle::CURSOR_DEFAULT );

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
                    if ( e.button.button == SDL_BUTTON_LEFT ) {
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
                                        // Only play click sound once per frame, in case
                                        // there are stacked actors.
                                        if ( !clickSoundPlayed ) {
                                            mAudioEngine->playSound( Player::MOUSE_CLICK_ID );
                                            clickSoundPlayed = true;
                                        }
                                    }

                                    handleEvent( actor, e );
                                }
                            }
                        }
                    }
                    break;


                case SDL_KEYDOWN:
                    switch ( e.key.keysym.sym ) {
                    default:
                        break;

                    case SDLK_ESCAPE:
                        if ( !mMainMenu ) {
                            mLevel.clearAll();
                            freeAndLoadLevel( 0 );
                        }
                        else {
                            Region r = mLevel.getActors()[0]->getRegion();
                            mLevel.clearAll();
                            freeAndLoadLevel( 0 );
                            mLevel.getActors()[0]->setRegion( r );
                        }
                        break;

					case SDLK_RETURN:
					{
						static const Uint8* keys = SDL_GetKeyboardState( nullptr );
						if ( keys[SDL_SCANCODE_LALT] || keys[SDL_SCANCODE_RALT] ) {
							mVideoEngine->swapFullscreen();
						}
					}
						break;

#ifdef DEBUG_TOOLS
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

                    case SDLK_5:
                        freeAndLoadLevel( 5 );
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

                    case SDLK_F5:
                        mSerializer.save( 1, mLevel.getScene(), mPlayer.getInventory() );
                        break;

                    case SDLK_w:
                        // Dilithium.
                        mPlayer.addItem( 166 );
                        break;
#endif
                    }
                    break;

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
        render( mLevel.getActors() );
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
#ifdef DEBUG_TOOLS
    if ( mDebugData.disableLighting ) {
        mVideoEngine->render( bg, 6, mLevel.getBGImageID() );
    }
    else {
        mVideoEngine->render( bg, ( mCurrentLevelID >= 5 ) ? 5 : 0, mLevel.getBGImageID() );
    }
#else
    mVideoEngine->render( bg, ( mCurrentLevelID >= 5 ) ? 5 : 0, mLevel.getBGImageID() );
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

#ifdef DEBUG_TOOLS
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
    if ( mMainMenu ) {
        Region r = mLevel.getActors()[0]->getRegion();

        mLevel.changeScene( value );

        mLevel.getActors()[0]->setRegion( r );
    }

    mLevel.changeScene( value );

#ifdef DEBUG_TOOLS
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
	if ( value != -1 ) {
		mAudioEngine->playSound( value );
	}    
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onNewGame( BaseActorPtr actor, const int32_t value )
{
    mSerializer.setSlot( value );
    
    freeAndLoadLevel( 1 );
    Player::Inventory emptyInventory;
    mSerializer.save( 1, mLevel.getScene(), emptyInventory );
    mPlayer.setInventory( emptyInventory );

    mVideoEngine->showTextbox( 
        "Dr. Burris expects all labs in his office by midnight. The clock is ticking..." );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onLoadGame( BaseActorPtr actor, const int32_t value )
{
    mSerializer.setSlot( value );

    // Get the values from the save file.
    int32_t level = 1, scene = 103;
    Player::Inventory inventory;
    if ( mSerializer.load( level, scene, inventory ) ) {
        // Load the specified level and set the scene.
        freeAndLoadLevel( level );
        mLevel.changeScene( scene );
    }
    else {
        freeAndLoadLevel( 1 );
    }

    // Give the player their inventory.
    mPlayer.setInventory( inventory );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::onDisplayText( BaseActorPtr actor, const int32_t value )
{

	std::string text = ".";
	if ( typeid( *actor ) == typeid( SceneLink ) ) {
		text = "Item required: " + std::dynamic_pointer_cast<SceneLink>(actor)->getText();
	}
    else if ( typeid( *actor ) == typeid( LevelLink ) ) {
        text = "Item required: " + std::dynamic_pointer_cast<LevelLink>( actor )->getText();
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
    static std::string lastPath( "" );

    // Downcast BaseActor smart pointer to AudioStreamActor smart pointer.
    std::string path = 
        std::dynamic_pointer_cast<AudioStreamActor>( actor )->getPath();

    if ( path != lastPath ) {
        mAudioEngine->playStream( path );
        lastPath = path;
    }
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Engine::freeAndLoadLevel( const int32_t id )
{
    if ( id == 0 ) {
        mLevel.clearAll();
    }

    mVideoEngine->deleteResourceGroup( LEVEL_RESOURCE );
    mAudioEngine->deleteSoundGroup( LEVEL_RESOURCE );
    mLevel.loadLevel( "res/lvl/" + std::to_string( id ) + ".lvl",
                      *mAudioEngine,
                      *mVideoEngine );

    // On level load events, save the player's progress.
    // (Except on loading main menu).
    if ( id != 0 ) {
        mSerializer.save( id, mLevel.getScene(), mPlayer.getInventory() );
        mMainMenu = false;
    }
    else {
        mMainMenu = true;
    }

    mCurrentLevelID = id;

#ifdef DEBUG_TOOLS
    while ( !mDebugData.scenes.empty() ) {
        mDebugData.scenes.pop();
    }
    mDebugData.scenes.push( mLevel.getScene() );
#endif
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
