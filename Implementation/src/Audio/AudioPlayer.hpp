/**
 * @file AudioPlayer.hpp
 * @brief Declares the AudioPlayer class
 */

#include <stdexcept>
#include <string>
#include <unordered_map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#ifndef MWRAP_AUDIOPLAYER_H
#define MWRAP_AUDIOPLAYER_H
namespace mediawrap {

  /**
   * @class AudioPlayer
   * Provides basic audio playing capabilities with WAV files.
   * Acts as an abstraction layer for SDL2.
   */
  class AudioPlayer {
    public:

      /**
       * Used to uniquely identify each audio sample.
       */
      typedef unsigned int AudioID;

      /**
       * Constructs a new audio player.
       * Enables SDL audio functionality.
       */
      AudioPlayer();
      
      /**
       * Deletes the audio player and all of its samples and streams.
       * Disables SDL audio functionality.
       */
      ~AudioPlayer();

      /**
       * Loads the given audio file and prepares it for streaming.
       * Only one audio stream can be loaded at a time. The previously
       * loaded stream will be deleted if this method is called multiple
       * times.
       * @param file_path
       *   The path of the file to load.
       */
      void load_stream(const std::string& file_path);
      
      /**
       * Plays the loaded audio stream loop+1 times.
       * If set to -1, the audio will loop indefinitely.
       * Only one audio stream can be played at a time.
       * @param loops
       *   The number of times to play the audio.
       *   A value of -1 is infinite. Defaults to looping infinitely.
       */
      void stream_audio(int loops=-1);

      /**
       * Loads the given audio sample into memory. Loading a sample into an
       * existing id will delete the sample associated with it before
       * the new sample is loaded.
       * @param id
       *   The unique id to store the sample under.
       * @param file_path
       *   The path of the audio file to load into memory.
       */
      void load_sample(AudioID id, const std::string& file_path);

      /**
       * Plays the given audio sample in the first available channel.
       * @param id
       *   The id of the audio sample to play.
       */
      void play_sample(AudioID id);

      /**
       * Deletes the sample created by a call to load_sample().
       * @param id
       *   The id of the sample to delete.
       */
      void delete_sample(AudioID id);

      /**
       * Deletes all samples created by a call to load_sample().
       */
      void clear_samples();

    private:
      static const int audio_rate = 44100;
      static const int audio_channels = 1;
      static const int audio_buffer = 4096;
      static const Uint16 audio_format = AUDIO_S16;
      std::unordered_map<AudioID, Mix_Chunk*> *audio_samples;
      Mix_Music* audio_stream;
  };
}

#endif /*MWRAP_AUDIOPLAYER_H*/
