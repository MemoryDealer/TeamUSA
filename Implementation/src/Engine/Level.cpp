// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Level.cpp
/// \brief Implements Level class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Assert.h"
#include "Level.h"

#include "Actor/ActorEvent.h"
#include "Actor/AudioStreamActor.h"
#include "Actor/DelayedAudioActor.h"
#include "Actor/DelayedSceneLink.h"
#include "Actor/DelayedVideoActor.h"
#include "Actor/InventoryItemActor.h"
#include "Actor/LevelLink.h"
#include "Actor/MovingActor.h"
#include "Actor/ResponsiveAudioActor.h"
#include "Actor/ResponsiveVideoActor.h"
#include "Actor/SceneLink.h"
#include "Actor/TextboxSpawnActor.h"
#include "Actor/VideoActor.h"
#include "Actor/VideoEventActor.h"
#include "Audio/AudioEngine.hpp"
#include "Video/VideoEngine.hpp"

using namespace teamusa;


static inline std::istream &operator >>(std::istream &fs, Region &dst)
{
    fs >> dst.x >> dst.y >> dst.w >> dst.h;
    return fs;
}

static inline std::istream &operator >>(std::istream &fs, ActorEventType &dst)
{
    std::string sType;

    if (fs >> sType)
    {
        if (sType == "ChangeScene")
            dst = ActorEventType::ChangeScene;
        else if (sType == "LoadLevel")
            dst = ActorEventType::LoadLevel;
        else if (sType == "PlayAudio")
            dst = ActorEventType::PlayAudio;
        else if (sType == "NewGame")
            dst = ActorEventType::NewGame;
        else if (sType == "LoadGame")
            dst = ActorEventType::LoadGame;
        else if (sType == "DisplayText")
            dst = ActorEventType::DisplayText;
        else if (sType == "ExitGame")
            dst = ActorEventType::ExitGame;
        else if (sType == "StreamAudio")
            dst = ActorEventType::StreamAudio;
        else
            dst = ActorEventType::Nil;
    }
    return fs;
}


static void loadError(const std::string &msg)
{
    std::cerr << msg << std::endl;
    Assert(false);
}

Level::Level( void )
: scenes()
, startScene( -1 )
, activeScene( 0 )
{

}

Level::Level( int levelID, AudioEngine &audioEngine, VideoEngine &videoEngine )
: scenes( )
, startScene( -1 )
, activeScene( 0 )
{

}

const ActorList& Level::getActors( void ) const
{
    Assert( scenes.find( activeScene ) != scenes.end() );
    return scenes.at(activeScene).actors;
}

const int Level::getBGImageID( void ) const
{
    Assert( scenes.find( activeScene ) != scenes.end() );
    return scenes.at( activeScene ).bgImageID;
}

const int Level::loadLevel(const std::string &path, AudioEngine &audioEngine, VideoEngine &videoEngine)
{
    std::string cmd;
    std::fstream fs(path.c_str(), std::ios_base::in);
    int curScene = -1;
    Scene scene;
    int resID;
    std::string resPath;   

//    scenes.clear();

    fs >> std::boolalpha;
    while (fs >> cmd)
    {
        if ( cmd.find_first_of('#') == 0 ) // handle comments with multiple hashtags
            std::getline(fs, cmd);
        else if (cmd == "SCENE")
        {
            if (curScene >= 0)
                loadError("unexpected SCENE (scenes cannot be nested)");
            fs >> curScene;
            /*if (scenes.find(curScene) != scenes.cend())
                loadError("scene with ID already exists");*/
            fs >> scene.bgImageID;
            #if defined ( DEBUG ) || defined ( _DEBUG )
            std::cout << "begin SCENE " << curScene << std::endl;
            #endif
        }
        else if (cmd == "ENDSCENE")
        {
            #if defined ( DEBUG ) || defined ( _DEBUG )
            std::cout << "ENDSCENE " << curScene << std::endl;
            #endif
            if (curScene < 0)
                loadError("unexpected ENDSCENE");
            // move scene actors into scene map
            scenes.insert(std::pair<int,Scene>(curScene, std::move(scene)));
            scene.actors.clear();
            curScene = -1;
        }
        else if (curScene < 0)
        {
            if (cmd == "IMAGE")
            {
                fs >> resID >> resPath;
                videoEngine.loadTexture(resPath, resID, ResourceGroup::LEVEL_RESOURCE);
            }
            else if (cmd == "AUDIO")
            {
                fs >> resID >> resPath;
                audioEngine.loadSound(resPath, resID, ResourceGroup::LEVEL_RESOURCE);
            }
            else if (cmd == "START_SCENE")
                fs >> startScene;
            else
                loadError(cmd + " is an unknown resource type");
        }
        else
        {
            // actors
            if (cmd == "AudioStreamActor")
                scene.actors.push_back(parseAudioStreamActor(fs));
            else if (cmd == "DelayedAudioActor")
                scene.actors.push_back(parseDelayedAudioActor(fs));
            else if ( cmd == "DelayedSceneLink" )
                scene.actors.push_back( parseDelayedSceneLink( fs ) );
            else if (cmd == "DelayedVideoActor")
                scene.actors.push_back(parseDelayedVideoActor(fs));
            else if (cmd == "InventoryItemActor")
                scene.actors.push_back(parseInventoryItemActor(fs));
            else if (cmd == "LevelLink")
                scene.actors.push_back(parseLevelLink(fs));
            else if (cmd == "MovingActor")
                scene.actors.push_back(parseMovingActor(fs));
            else if (cmd == "ResponsiveAudioActor")
                scene.actors.push_back(parseResponsiveAudioActor(fs));
            else if (cmd == "ResponsiveVideoActor")
                scene.actors.push_back(parseResponsiveVideoActor(fs));
            else if (cmd == "SceneLink")
                scene.actors.push_back(parseSceneLink(fs));
            else if (cmd == "TextboxSpawnActor")
                scene.actors.push_back(parseTextboxSpawnActor(fs));
            else if (cmd == "VideoActor")
                scene.actors.push_back(parseVideoActor(fs));
            else if (cmd == "VideoEventActor")
                scene.actors.push_back(parseVideoEventActor(fs));
            else
                loadError(cmd + " is an unknown actor type");
        }
    }

    if (curScene >= 0)
        loadError("unexpected EOF before ENDSCENE");

    activeScene = startScene;

    #if defined ( DEBUG ) || defined ( _DEBUG )
      for(auto& i : scenes){
        std::cout << "Scene " << i.first << std::endl;
      }
      lastLevelPath = path;
    #endif    
    return activeScene;
}

#ifdef DEBUG_TOOLS
void Level::reloadLast( AudioEngine &audioEngine, VideoEngine &videoEngine )
{
    scenes.clear();
    loadLevel( lastLevelPath, audioEngine, videoEngine );
}
#endif

const int Level::getScene()
{
  return activeScene;
}

void Level::clearAll( void )
{
    scenes.clear();
}

void Level::changeScene( const int sceneID )
{
    Assert( scenes.find( sceneID ) != scenes.end() );
    activeScene = sceneID;

#if defined ( DEBUG ) || defined ( _DEBUG )
    std::cout << "Active Scene: " << activeScene << std::endl;
    std::cout << "DEBUG INFO - Scene changed" << std::endl
        << "ID: " << sceneID << std::endl
        << "Num Actors: " << scenes.at(activeScene).actors.size() << std::endl
        << std::endl;
#endif
}

BaseActorPtr Level::parseAudioStreamActor(std::fstream &fs)
{
    std::string path;

    fs >> path;
    return BaseActorPtr( new AudioStreamActor( path ) );
}

BaseActorPtr Level::parseDelayedAudioActor(std::fstream &fs)
{
    int audioID, delaySteps;

    fs >> audioID >> delaySteps;
    return BaseActorPtr( new DelayedAudioActor( audioID, delaySteps ) );
}

BaseActorPtr Level::parseDelayedSceneLink( std::fstream& fs )
{
    Region region;
    int sceneID, requiredItemID;
    int delay;
    std::string itemRequiredText;

    fs >> sceneID >> region >> delay >> requiredItemID;
    std::getline( fs, itemRequiredText );
    return BaseActorPtr( new DelayedSceneLink( region, sceneID, itemRequiredText, requiredItemID, delay ) );
}

BaseActorPtr Level::parseDelayedVideoActor(std::fstream &fs)
{
    Region region;
    int textureID, delaySteps, disappearStep, layer;

    fs >> region >> textureID >> delaySteps >> disappearStep >> layer;
    return BaseActorPtr( new DelayedVideoActor( region, textureID, delaySteps, disappearStep, layer ) );
}

BaseActorPtr Level::parseInventoryItemActor(std::fstream &fs)
{
    Region region;
    int itemID, textureID, layer;

    fs >> region >> itemID >> textureID >> layer;
    return BaseActorPtr( new InventoryItemActor( region, itemID, textureID, layer ) );
}

BaseActorPtr Level::parseLevelLink(std::fstream &fs)
{
    int levelID;
    Region region;
    int sceneID, itemID;
    std::string itemRequiredText;

    fs >> levelID >> region >> sceneID >> itemID;
    std::getline(fs, itemRequiredText);
    return BaseActorPtr( new LevelLink( region, levelID, sceneID, itemRequiredText, itemID ) );
}

BaseActorPtr Level::parseMovingActor(std::fstream &fs)
{
    Region startRegion, endRegion;
    int textureID, layer, transitionSteps;
    bool moveOnSpawn;

    fs >> startRegion >> endRegion >> textureID >> layer >> transitionSteps >> moveOnSpawn;
    return BaseActorPtr( new MovingActor( startRegion, endRegion, textureID, layer, transitionSteps, moveOnSpawn ) );
}

BaseActorPtr Level::parseResponsiveAudioActor(std::fstream &fs)
{
    Region region;
    int hoverAudioID, clickAudioID;

    fs >> region >> hoverAudioID >> clickAudioID;
    return BaseActorPtr( new ResponsiveAudioActor( region, hoverAudioID, clickAudioID ) );
}

BaseActorPtr Level::parseResponsiveVideoActor(std::fstream &fs)
{
    Region region;
    int hoverTextureID, clickTextureID, defaultTextureID, layer;

    fs >> region >> hoverTextureID >> clickTextureID >> defaultTextureID >> layer;
    return BaseActorPtr( new ResponsiveVideoActor( region, hoverTextureID, clickTextureID, defaultTextureID, layer ) );
}

BaseActorPtr Level::parseSceneLink(std::fstream &fs)
{
    Region region;
    int sceneID, requiredItemID;
    std::string itemRequiredText;

    fs >> sceneID >> region >> requiredItemID;
    std::getline(fs, itemRequiredText);
    return BaseActorPtr( new SceneLink( region, sceneID, itemRequiredText, requiredItemID ) );
}

BaseActorPtr Level::parseTextboxSpawnActor(std::fstream &fs)
{
    Region region;
    std::string text;

    fs >> region;
    std::getline(fs, text);
    return BaseActorPtr( new TextboxSpawnActor( region, text ) );
}

BaseActorPtr Level::parseVideoActor(std::fstream &fs)
{
    Region region;
    int textureID, layer;

    fs >> region >> textureID >> layer;
    return BaseActorPtr( new VideoActor( region, textureID, layer ) );
}

BaseActorPtr Level::parseVideoEventActor(std::fstream &fs)
{
    Region region;
    int textureID;
    ActorEventType eventType;
    int eventValue, layer;

    fs >> region >> textureID >> eventType >> eventValue >> layer;
    return BaseActorPtr( new VideoEventActor( region, textureID, eventType, eventValue, layer ) );
}
