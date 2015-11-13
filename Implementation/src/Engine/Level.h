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

    class Level
    {
    private:
        struct Scene
        {
            std::vector<BaseActorPtr> actors;
            int bgImageID;
        };

    private:
        std::map<int, Scene> scenes;
        int startScene;

    public:
        Level(int levelID, AudioEngine &audioEngine, VideoEngine &videoEngine);
    private:
        void loadLevel(const std::string &path, AudioEngine &audioEngine, VideoEngine &videoEngine);
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
