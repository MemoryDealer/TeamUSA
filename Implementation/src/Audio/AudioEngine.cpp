/**
 * @file AudioEngine.cpp
 * @brief Declares the AudioEngine class
 */

#include "AudioEngine.hpp"

void teamusa::AudioEngine::loadSound(
 const std::string &path, AudioID id, ResourceGroup group){
  if(id < MAX_RESERVED_ID)
    throw std::runtime_error(
     "AudioEngine::loadSound: Unable to use reserved audio id");
  this->audioPlayer.load_sample(id, path);
  // Choose correct vector
  if(group == CORE_RESOURCE)
    this->coreResources.push_back(id);
  else if(group == LEVEL_RESOURCE)
    this->levelResources.push_back(id);
}

void teamusa::AudioEngine::playSound(AudioID id){
  this->audioPlayer.play_sample(id);
}

void teamusa::AudioEngine::playStream(const std::string &path){
  this->audioPlayer.load_stream(path);
  this->audioPlayer.stream_audio();
}

void teamusa::AudioEngine::deleteSound(AudioID id){
  std::vector<AudioID>::iterator iter;
  if(id < MAX_RESERVED_ID)
    throw std::runtime_error(
     "AudioEngine::deleteSound: Unable to use reserved audio id");
  this->audioPlayer.delete_sample(id);
  // Clear id from core resources
  iter = this->coreResources.begin();
  while(iter != this->coreResources.end()){
    if(*iter == id) iter = this->coreResources.erase(iter);
    else ++iter;
  }
  // Clear id from level resources
  iter = this->levelResources.begin();
  while(iter != this->levelResources.end()){
    if(*iter == id) iter = this->levelResources.erase(iter);
    else ++iter;
  }
}

void teamusa::AudioEngine::deleteSoundGroup(ResourceGroup resourceGroup){
  std::vector<AudioID>::iterator iter;
  std::vector<AudioID> *vector;
  // Choose correct vector
  if(resourceGroup == CORE_RESOURCE)
    vector = &this->coreResources;
  else if(resourceGroup == LEVEL_RESOURCE)
    vector = &this->levelResources;
  // Delete every texture stored in vector
  for(iter = vector->begin(); iter != vector->end(); ++iter){
    this->audioPlayer.delete_sample(*iter);
  }
  // Clear vector contents
  vector->clear();
}
