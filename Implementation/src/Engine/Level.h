// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Level.h
/// \brief Declares Level class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

#include "Headers.h"

namespace teamusa
{
    class BaseActor;
    class AudioEngine;
    class VideoEngine;

    typedef std::shared_ptr<BaseActor> BaseActorPtr;
    typedef std::vector<BaseActorPtr> ActorList;

    class Level
    {
    private:
        struct Scene
        {
            ActorList actors;
            int bgImageID;
        };

    private:
        std::map<int, Scene> scenes;
        int startScene;
        int activeScene;

    public:
        Level( void );
        Level(int levelID, AudioEngine &audioEngine, VideoEngine &videoEngine);
        const ActorList& getActors( void ) const;
        const int getBGImageID( void ) const;
        void loadLevel( const std::string &path, AudioEngine &audioEngine, VideoEngine &videoEngine );

        void changeScene( const int sceneID );

    private:
        
        BaseActorPtr parseAudioStreamActor(std::fstream &fs);
        BaseActorPtr parseDelayedAudioActor(std::fstream &fs);
        BaseActorPtr parseDelayedVideoActor(std::fstream &fs);
        BaseActorPtr parseInventoryItemActor(std::fstream &fs);
        BaseActorPtr parseLevelLink(std::fstream &fs);
        BaseActorPtr parseMovingActor(std::fstream &fs);
        BaseActorPtr parseResponsiveAudioActor(std::fstream &fs);
        BaseActorPtr parseResponsiveVideoActor(std::fstream &fs);
        BaseActorPtr parseSceneLink(std::fstream &fs);
        BaseActorPtr parseTextboxSpawnActor(std::fstream &fs);
        BaseActorPtr parseVideoActor(std::fstream &fs);
        BaseActorPtr parseVideoEventActor(std::fstream &fs);
    };
}
