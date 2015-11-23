/**
 * @file AudioPlayer.cpp
 * @brief Implements the AudioPlayer class
 */

#include "AudioPlayer.hpp"

mediawrap::AudioPlayer::AudioPlayer(){
  this->audio_stream = NULL;
  this->audio_samples = new std::unordered_map<AudioID, Mix_Chunk*>();
  if(SDL_InitSubSystem(SDL_INIT_AUDIO) != 0){
    throw std::runtime_error(
     "Unable to initialize audio: " + std::string(SDL_GetError()));
  }
  if(Mix_Init(0) != 0){
    throw std::runtime_error(
     "Unable to initialize SDL_mixer: " + std::string(Mix_GetError()));
  }
  if(Mix_OpenAudio(
   audio_rate, audio_format, audio_channels, audio_buffer) < 0){
    throw std::runtime_error(
     "Unable to open audio channel: " + std::string(Mix_GetError()));
  }
  Mix_Volume(-1, MIX_MAX_VOLUME);
}

mediawrap::AudioPlayer::~AudioPlayer(){
  Mix_PauseMusic();
  if(this->audio_stream)
    Mix_FreeMusic(this->audio_stream);
  this->clear_samples();
  Mix_Quit();
  SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

void mediawrap::AudioPlayer::load_stream(const std::string& file_path){
  //Pause any streaming in progress.
  Mix_PauseMusic();
  //Unload existing stream
  if(this->audio_stream)
    Mix_FreeMusic(this->audio_stream);
  this->audio_stream = Mix_LoadMUS(file_path.c_str());
  if(!this->audio_stream)
    throw std::runtime_error("Unable to load audio stream: " + file_path);
}

void mediawrap::AudioPlayer::stream_audio(int loops){
  if(Mix_PlayMusic(this->audio_stream, loops) == -1)
    throw std::runtime_error("Unable to play audio stream.");
}

void mediawrap::AudioPlayer::load_sample(
AudioID id, const std::string& file_path){
  std::unordered_map<AudioID, Mix_Chunk*>::iterator iter;
  Mix_Chunk* sample;
  // Check if key exists and free old chunk
  iter = this->audio_samples->find(id);
  if(iter != this->audio_samples->end())
    Mix_FreeChunk(iter->second);
  sample = Mix_LoadWAV(file_path.c_str());
  if(!sample)
    throw std::runtime_error("Unable to load audio sample: " + file_path + " (" + Mix_GetError() + ")");
  else
    this->audio_samples->insert(std::make_pair(id, sample));
}

void mediawrap::AudioPlayer::play_sample(AudioID id){
  std::unordered_map<AudioID, Mix_Chunk*>::iterator iter;
  iter = this->audio_samples->find(id);
  if(iter == this->audio_samples->end() ||
   Mix_PlayChannel(-1, iter->second, 0) == -1){
    throw std::runtime_error("Unable to play audio sample (" + std::to_string( id ) + ").");
  }
}


void mediawrap::AudioPlayer::delete_sample(AudioID id){
  std::unordered_map<AudioID, Mix_Chunk*>::iterator iter;
  iter = this->audio_samples->find(id);
  if(iter != this->audio_samples->end())
    Mix_FreeChunk(iter->second);
  this->audio_samples->erase(iter);
}

void mediawrap::AudioPlayer::clear_samples(){
  std::unordered_map<AudioID, Mix_Chunk*>::iterator iter, temp;
  iter = this->audio_samples->begin();
  while(iter != this->audio_samples->end()){
    temp = iter;
    Mix_FreeChunk(iter->second);
    ++iter;
    this->audio_samples->erase(temp);
  }
}

