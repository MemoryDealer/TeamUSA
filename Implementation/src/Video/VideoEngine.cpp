/**
 * @file VideoEngine.cpp
 * @brief Implements the VideoEngine class
 */

#include "VideoEngine.hpp"

using namespace teamusa;

VideoEngine::VideoEngine(
 const std::string &title, unsigned int width, unsigned int height){
  const int FONT_SIZE = 16;
  this->videoContext = new VideoContext(title, width, height);
  this->videoContext->load_font("res/font.ttf", FONT_SIZE);
  this->textboxActive = false;
  // Create initial layers with IDs 0-6
  for(unsigned int i=0; i<NUM_LAYERS; ++i){
    this->layers[i] = i;
    // Create layer 4 as shadow blending
    if(i == SHADOW_LAYER)
      this->videoContext->create_texture(
       i, width, height, mediawrap::VideoContext::BLENDMODE_MOD);
    else
      this->videoContext->create_texture(i, width, height);
  }
  // Calculate textbox draw location
  this->textboxRegion.w = width / 3;
  this->textboxRegion.h = height / 4;
  this->textboxRegion.x = (width - this->textboxRegion.w) / 2;
  this->textboxRegion.y = (height - this->textboxRegion.h) / 2;
  // Calculate textbox padding
  this->textboxPadding = {
   FONT_SIZE,
   FONT_SIZE, 
   this->textboxRegion.w - FONT_SIZE,
   this->textboxRegion.h - FONT_SIZE
  };
  // Create textbox texture
  this->videoContext->create_texture(
   TEXT_LAYER, this->textboxRegion.w, this->textboxRegion.h);
  // Initialize layers
  this->clearLayers();
  this->videoContext->render_clear(TEXT_LAYER);
}

VideoEngine::~VideoEngine(){
  delete this->videoContext;
}

void VideoEngine::loadTexture(
 const std::string &path, TextureID id, ResourceGroup group){
  if(id < MAX_RESERVED_ID)
    throw std::runtime_error(
     "VideoEngine::loadTexture: Unable to use reserved texture id");
  this->videoContext->load_texture(id, path);
  if(group == CORE_RESOURCE)
    this->coreResources.push_back(id);
  else if(group == LEVEL_RESOURCE)
    this->levelResources.push_back(id);
}

void VideoEngine::render(const Region &region, const unsigned int layer, const TextureID id){
  this->videoContext->render_onto(this->layers[layer], id, &region, NULL);
}

void VideoEngine::renderDebugBox( const Region& region, 
                                  const VideoContext::DebugColor color ){
    this->videoContext->renderDebugBox( region, color, 6 );
}

void VideoEngine::renderRotate(
 Region &region, unsigned int layer, TextureID id, float angle){
  this->videoContext->render_rotate(
   this->layers[layer], id, &region, NULL, angle);
}

void VideoEngine::swapFullscreen( void ){
	videoContext->swapFullscreen();
}

bool VideoEngine::isShowingTextbox(){
  return this->textboxActive;
}

void VideoEngine::showTextbox(const std::string &text){
  this->videoContext->fill_texture(TEXT_LAYER, 80, 80, 120, 200);
  this->videoContext->render_text(
   TEXT_LAYER, &(this->textboxPadding), text, 255, 255, 255, 255);
  this->textboxActive = true;
}

void VideoEngine::hideTextbox(){
  this->videoContext->render_clear(TEXT_LAYER);
  this->textboxActive = false;
}

void VideoEngine::deleteTexture(TextureID id){
  std::vector<TextureID>::iterator iter;
  if(id < MAX_RESERVED_ID)
    throw std::runtime_error(
     "VideoEngine::deleteTexture: Unable to use reserved texture id");
  this->videoContext->delete_texture(id);

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

void VideoEngine::display(){
  // Draw each layer
  for(unsigned int i = 0; i < NUM_LAYERS; ++i){
    this->videoContext->render(layers[i], NULL, NULL);
  }
  // Draw textbox layer if necessary
  if(this->textboxActive)
    this->videoContext->render(TEXT_LAYER, &this->textboxRegion, NULL);
  // Display final image
  this->videoContext->display();
  // Prepare for next draw
  this->clearLayers();
}

void VideoEngine::clearLayers(){
  // NUM_LAYERS-1 to avoid writing to the textbox layer
  for(unsigned int i=0; i<NUM_LAYERS; ++i){
    // Clear layer 4 with shadows
    if(i == SHADOW_LAYER)
      this->videoContext->fill_texture(i, 40, 40, 40, 255);
    else
      this->videoContext->render_clear(i);
  }
}

