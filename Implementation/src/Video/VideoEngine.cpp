#include "VideoEngine.hpp"

using namespace teamusa;

VideoEngine::VideoEngine(std::string &title, unsigned int width, unsigned int height){
  this->videoContext = new VideoContext(title, width, height);
  this->videoContext->load_font("res/font.ttf", 8);
  this->textboxActive = false;
  // Calculate textbox location
  this->textboxRegion.w = width / 2;
  this->textboxRegion.h = width / 3;
  this->textboxRegion.x = this->textboxRegion.w / 2;
  this->textboxRegion.y = this->textboxRegion.h / 2;
  // Create initial layers with IDs 0-7
  for(unsigned int i=0; i<NUM_LAYERS; ++i){
    // Create layer 4 as shadow blending
    if(i == SHADOW_LAYER)
      this->videoContext->create_texture(
       i, this->textboxRegion.w, this->textboxRegion.h,
       mediawrap::VideoContext::BLENDMODE_MOD
      );
    else
      this->videoContext->create_texture(i, width, height);
  }
}

VideoEngine::~VideoEngine(){
  delete this->videoContext;
}

void VideoEngine::loadTexture(
 std::string &path, TextureID id, ResourceGroup group){
  this->videoContext->load_texture(id, path);
  if(group == CORE_RESOURCE)
    this->coreResources.push_back(id);
  else if(group == LEVEL_RESOURCE)
    this->levelResources.push_back(id);
}

void VideoEngine::render(Region &region, unsigned int layer, TextureID id){
  this->videoContext->render_onto(this->layers[layer], id, &region, NULL);
}

void VideoEngine::renderRotate(
 Region &region, unsigned int layer, TextureID id, float angle){
  this->videoContext->render_rotate(
   this->layers[layer], id, &region, NULL, angle);
}

bool VideoEngine::isShowingTextbox(){
  return this->textboxActive;
}

void VideoEngine::showTextbox(std::string &text){
  this->videoContext->fill_texture(layers[TEXT_LAYER], 80, 80, 120, 200);
  this->videoContext->render_text(
   layers[TEXT_LAYER], &(this->textboxRegion), text, 255, 255, 255, 255);
}

void VideoEngine::hideTextbox(){
  this->videoContext->render_clear(layers[TEXT_LAYER]);
}

void VideoEngine::deleteTexture(TextureID id){
  this->videoContext->delete_texture(id);
}

void VideoEngine::deleteResourceGroup(ResourceGroup resourceGroup){
  std::vector<TextureID>::iterator iter;
  std::vector<TextureID> *vector;
  // Choose correct vector
  if(resourceGroup == CORE_RESOURCE)
    vector = &this->coreResources;
  else if(resourceGroup == LEVEL_RESOURCE)
    vector = &this->levelResources;
  // Delete every texture stored in vector
  for(iter = vector->begin(); iter != vector->end(); ++iter){
    this->videoContext->delete_texture(*iter);
  }
  // Clear vector contents
  vector->clear();
}

