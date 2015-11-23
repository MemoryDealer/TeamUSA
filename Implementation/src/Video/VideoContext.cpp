/**
 * @file VideoContext.cpp
 * @brief Implements the VideoContext class
 */

#include "VideoContext.hpp"

using namespace mediawrap;

VideoContext::VideoContext(
const std::string& title, unsigned int width, unsigned int height){
  // Create display and get a handle to its renderer.
  this->video_display = new VideoDisplay(title, width, height); 
  this->renderer = this->video_display->get_renderer();
  this->textures = new std::unordered_map<TextureID, SDL_Texture*>();
  this->font = NULL;
  // Set Defaults
  SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_NONE);
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
  SDL_SetRenderTarget(this->renderer, NULL);
  SDL_RenderClear(this->renderer);
}

VideoContext::~VideoContext(void){
  // Delete all textures in the map
  texture_iter iter = this->textures->begin();
  while(iter != this->textures->end()){
    SDL_DestroyTexture(iter->second);
    this->textures->erase(iter++);
  }
  delete this->textures;
  if(this->font)
    TTF_CloseFont(this->font);
  SDL_DestroyRenderer(this->renderer);
  delete this->video_display;
}

void VideoContext::display(void){
  SDL_RenderPresent(this->renderer);
}

VideoContext::Region VideoContext::load_texture(
TextureID id, const std::string& image_path, BlendMode blend){
  Region rectangle;
  SDL_Texture *texture;
  SDL_Surface *image;
  // Unload existing texture in map
  this->delete_texture(id);
  // Read in image
  image = IMG_Load(image_path.c_str());
  if(!image)
    throw std::runtime_error("Unable to load image: " + image_path);
  rectangle = {0, 0, image->w, image->h};
  // Convert image to texture
  texture = SDL_CreateTextureFromSurface(this->renderer, image);
  SDL_FreeSurface(image);
  SDL_SetTextureBlendMode(texture, (SDL_BlendMode)blend);
  if(!texture)
    throw std::runtime_error("Unable to load texture: " + image_path);
  this->textures->insert(std::make_pair(id, texture));
  return rectangle;
}

VideoContext::Region VideoContext::create_texture(
TextureID id, int width, int height, BlendMode blend){
  SDL_Texture *texture;
  Region rectangle = {0, 0, width, height};
  // Unload existing texture in map
  this->delete_texture(id);
  texture = SDL_CreateTexture(this->renderer, 
   SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
  SDL_SetTextureBlendMode(texture, (SDL_BlendMode)blend);
  if(!texture)
    throw std::runtime_error("Unable to create blank texture.");
  this->textures->insert(std::make_pair(id, texture));
  return rectangle;
}

void VideoContext::delete_texture(TextureID id){
  // Free texture and delete from map
  VideoContext::texture_iter iter = this->textures->find(id);
  if(iter != this->textures->end()){
    SDL_DestroyTexture(iter->second);
    this->textures->erase(iter);
  }
}

void VideoContext::render(TextureID id, Region* dest, Region* src){
  VideoContext::texture_iter iter = this->textures->find(id);
  if(iter == this->textures->end())
    throw std::runtime_error("Unable to render. Invalid texture id.");
  SDL_SetRenderTarget(this->renderer, NULL);
  SDL_RenderCopy(this->renderer, iter->second, src, dest);
}

void VideoContext::renderDebugBox( const Region& region,
                                   const DebugColor color,
                                   const TextureID layer )
{
    Uint8 colors[3][3] = 
    { { 255, 0, 0 }, 
    { 0, 255, 0 }, 
    { 0, 0, 255} };

    SDL_SetRenderTarget( this->renderer, this->textures->at( layer ) );
    SDL_SetRenderDrawBlendMode( this->renderer, SDL_BLENDMODE_BLEND );
    SDL_SetRenderDrawColor( this->renderer,
                            colors[color][0],
                            colors[color][1],
                            colors[color][2],
                            50 );
    SDL_RenderFillRect( this->renderer, &region );

    SDL_SetRenderDrawColor( this->renderer,
                            colors[color][0],
                            colors[color][1],
                            colors[color][2], 
                            255 );
    SDL_RenderDrawRect( this->renderer, &region );
}

void VideoContext::render_onto(TextureID dest_id, TextureID src_id,
const Region* dest_region, Region* src_region){
  VideoContext::texture_iter dest_iter = this->textures->find(dest_id);
  VideoContext::texture_iter src_iter = this->textures->find(src_id);
  if(dest_iter == this->textures->end())
    throw std::runtime_error("Unable to render_onto. Invalid dest id.");
  if ( src_iter == this->textures->end() ) {
      std::string err = std::string( "Unable to render_onto. Invalid src id (" );
      err += std::to_string( src_id ) + ")" + "(dst_id = " + std::to_string( dest_id) + ")";
      throw std::runtime_error( err );
  }
  SDL_SetRenderTarget(this->renderer, dest_iter->second);
  SDL_RenderCopy(this->renderer, src_iter->second, src_region, dest_region);
  SDL_SetRenderTarget(this->renderer, NULL);
}

void VideoContext::render_rotate(TextureID dest_id, TextureID src_id,
Region* dest_region, Region* src_region, double angle, Flip flip){
  VideoContext::texture_iter dest_iter = this->textures->find(dest_id);
  VideoContext::texture_iter src_iter = this->textures->find(src_id);
  if(dest_iter == this->textures->end())
    throw std::runtime_error("Unable to render_rotate. Invalid dest id.");
  if(src_iter == this->textures->end())
    throw std::runtime_error("Unable to render_rotate. Invalid src id.");
  SDL_SetRenderTarget(this->renderer, dest_iter->second);
  SDL_RenderCopyEx(this->renderer, src_iter->second,
   src_region, dest_region, angle, NULL, (SDL_RendererFlip)flip);
  SDL_SetRenderTarget(this->renderer, NULL);
}

void VideoContext::render_clear(){
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
  SDL_RenderClear(this->renderer);
}

void VideoContext::render_clear(TextureID id){
  VideoContext::texture_iter iter = this->textures->find(id);
  if(iter == this->textures->end())
    throw std::runtime_error("Unable to render_clear. Invalid texture id.");
  SDL_SetRenderTarget(this->renderer, iter->second);
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
  SDL_RenderClear(this->renderer);
  SDL_SetRenderTarget(this->renderer, NULL);
}

void VideoContext::fill_texture(
TextureID id, int r, int g, int b, int alpha){
  VideoContext::texture_iter iter = this->textures->find(id);
  if(iter == this->textures->end())
    throw std::runtime_error("Unable to fill_texture. Invalid texture id.");
  SDL_SetRenderTarget(this->renderer, iter->second);
  SDL_SetRenderDrawColor(this->renderer, r, g, b, alpha);
  SDL_RenderFillRect(this->renderer, NULL);
  SDL_SetRenderTarget(this->renderer, NULL);
}

void VideoContext::load_font(
const std::string& font_path, int font_size){
  this->font = TTF_OpenFont(font_path.c_str(), font_size);
  if(!this->font){
    throw std::runtime_error("Unable to load font: " + font_path);
  }
}

void VideoContext::render_text(TextureID dest_id, Region* dest_region,
const std::string& text, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* text_texture;
  SDL_Surface* surface;
  SDL_Color color = {r, g, b, a};
  // Ensure the destination is not null (needed to enforce text wrapping)
  if(!dest_region)
    throw std::runtime_error("Unable to render text with NULL region.");
  // Ensure font is loaded
  if(!this->font)
    throw std::runtime_error("Unable to render_text. No font loaded.");
  // Fetch destination texture
  VideoContext::texture_iter iter = this->textures->find(dest_id);
  if(iter == this->textures->end())
    throw std::runtime_error("Unable to render_text. Invalid dest_id.");
  // Create wrapped-text surface
  surface = TTF_RenderText_Blended_Wrapped(
   this->font, text.c_str(), color, dest_region->w);
  SDL_Rect width_rect = {dest_region->x, dest_region->y, surface->w, surface->h};
  // Create and render texture
  text_texture = SDL_CreateTextureFromSurface(this->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_SetRenderTarget(this->renderer, iter->second);
  SDL_RenderCopy(this->renderer, text_texture, NULL, &width_rect);
  SDL_DestroyTexture(text_texture);
  SDL_SetRenderTarget(this->renderer, NULL);
}

void VideoContext::swapFullscreen( void ){
	video_display->swapFullscreen();
}
