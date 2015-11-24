/**
 * @file AudioEngine.hpp
 * @brief Declares the AudioEngine class
 */

#include <string>
#include <vector>
#include "AudioPlayer.hpp"
#include "Engine/ResourceGroup.hpp"

#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

namespace teamusa {

  using mediawrap::AudioPlayer;
  typedef mediawrap::AudioPlayer::AudioID AudioID;

  /**
   * @class AudioEngine
   * Provides project-specific audio functionality for Legend of the Great Unwashed.
   */
  class AudioEngine {
    private:
      static const AudioID MAX_RESERVED_ID = 1000;
      std::vector<AudioID> coreResources;
      std::vector<AudioID> levelResources;
      AudioPlayer audioPlayer;
    public:

      /**
       * Loads the given sound file and associates it with the given id.
       * @param path
       *  The relative path of the sound file to load.
       * @param id
       *  The id to associate with the given sound file.
       */
      void loadSound(const std::string &path, AudioID id, ResourceGroup group);

      /**
       * Plays the sound associated with the given id.
       * @param id
       *  The id of the sound to play.
       */
      void playSound(AudioID id);

      /**
       * Plays the given stream in a loop continuously.
       * @param path
       *  The path of the audio to stream.
       */
      void playStream(const std::string &path);

      /**
       * Deletes the given sound from memory.
       * @param id
       *  The id of the audio to delete.
       */
      void deleteSound(AudioID id);

      /**
       * Deletes the entire group of sounds.
       * @param 
       */
      void deleteSoundGroup(ResourceGroup resourceGroup);
  };
}
#endif /* AUDIOENGINE_H */
