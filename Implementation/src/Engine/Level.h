
#pragma once

#include "Headers.h"

namespace teamusa
{
    class BaseActor;
    class AudioEngine;
    class VideoEngine;

    class Level
    {
    private:
        struct Scene
        {
            std::vector<BaseActor> actors;
            int bgImageID;
        };

    private:
        std::map<int, Scene> scenes;
        int startScene;

    public:
        Level(int levelID, AudioEngine &audioEngine, VideoEngine &videoEngine);
    private:
        void loadLevel(const std::string &path, AudioEngine &audioEngine, VideoEngine &videoEngine);
        BaseActor parseAudioStreamActor(std::fstream &fs);
        BaseActor parseDelayedAudioActor(std::fstream &fs);
        BaseActor parseDelayedVideoActor(std::fstream &fs);
        BaseActor parseInventoryItemActor(std::fstream &fs);
        BaseActor parseLevelLink(std::fstream &fs);
        BaseActor parseMovingActor(std::fstream &fs);
        BaseActor parseResponsiveAudioActor(std::fstream &fs);
        BaseActor parseResponsiveVideoActor(std::fstream &fs);
        BaseActor parseSceneLink(std::fstream &fs);
        BaseActor parseTextboxSpawnActor(std::fstream &fs);
        BaseActor parseVideoActor(std::fstream &fs);
        BaseActor parseVideoEventActor(std::fstream &fs);
    };
}
