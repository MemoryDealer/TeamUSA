// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Level.h
/// \brief Declares Level class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

#include <unordered_map>
#include "Headers.h"

namespace teamusa
{
    class BaseActor;
    class AudioEngine;
    class VideoEngine;

    typedef std::shared_ptr<BaseActor> BaseActorPtr;
    typedef std::vector<BaseActorPtr> ActorList;

	///
	/// \class Level
	/// \brief A Level is a container of Scenes and Actors corresponding to 
	///		those scenes.
    class Level
    {
    private:
		/// 
		/// \class Scene
		/// \brief A scene is a collection of images (Actors) that is displayed on
		///		the screen.
        struct Scene
        {
            ActorList actors;
            int bgImageID;
        };

    private:
        std::unordered_map<int, Scene> scenes;
        int startScene;
        int activeScene;
#ifdef DEBUG_TOOLS
        std::string lastLevelPath;
#endif

    public:				
        Level( void );
        Level(int levelID, AudioEngine &audioEngine, VideoEngine &videoEngine);

		///
		/// \brief Returns the list of actors in the current scene.
        const ActorList& getActors( void ) const;

		///
		/// \brief Returns the textureID of the background image in the current scene.
        const int getBGImageID( void ) const;

		///
		/// \brief Parses the specified level file, loads textures, audio samples, and stores
		///		the actors in a hash table.
		/// \param path The file path to the .lvl file.
		/// \param audioEngine A reference to the audio engine being used.
		/// \param videoEngine A reference to the video engine being used.
        const int loadLevel( const std::string &path, AudioEngine &audioEngine, VideoEngine &videoEngine );

		///
		/// \brief Changes the currently active scene. Subsequent calls to getActors() will return 
		///		the actors in that scene.
		/// \param sceneID The ID of the new scene.
        void changeScene( const int sceneID );

		///
		/// \briefs Returns the index of the currently active scene.
        const int getScene();

		///
		/// \brief Removes all loaded scenes and actors from memory.
        void clearAll( void );

#ifdef DEBUG_TOOLS
		///
		/// \brief Frees and reloads the last loaded level file.
        void reloadLast( AudioEngine &audioEngine, VideoEngine &videoEngine );
#endif

    private:
        
        BaseActorPtr parseAudioStreamActor(std::fstream &fs);
        BaseActorPtr parseDelayedAudioActor(std::fstream &fs);
        BaseActorPtr parseDelayedSceneLink( std::fstream& fs );
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
