/**
 * @file VideoDisplay.cpp
 * @brief Implements the VideoDisplay class
 */

#include "VideoDisplay.hpp"

mediawrap::VideoDisplay::VideoDisplay(
const std::string& title, unsigned int width, unsigned int height){
  this->window = NULL;
  // Init SDL
  if(SDL_InitSubSystem(SDL_INIT_VIDEO) != 0){
    throw std::runtime_error(
     "Unable to create window: " + std::string(SDL_GetError()));
  }
  // Init IMG
  if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    throw std::runtime_error(
     "Unable to init SDL_Image: " + std::string(IMG_GetError()));
  }
  // Init TTF
  if(TTF_Init() != 0){
    IMG_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    throw std::runtime_error(
     "Unable to init SDL_ttf: " + std::string(TTF_GetError()));
  }
  // Create Window
  this->window = SDL_CreateWindow(
   title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  if(!this->window){
    TTF_Quit();
    IMG_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    throw std::runtime_error(
     "Unable to create window: " + std::string(SDL_GetError()));
  }
}

mediawrap::VideoDisplay::~VideoDisplay(void){
  SDL_DestroyWindow(this->window);
  TTF_Quit();
  IMG_Quit();
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

SDL_Renderer* mediawrap::VideoDisplay::get_renderer(void){
  // Create Renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(
   this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!renderer){
    throw std::runtime_error(
     "Unable to create renderer: " + std::string(SDL_GetError()));
  }
  return renderer;
}

void mediawrap::VideoDisplay::swapFullscreen( void ){
	static bool fullscreen = false; // We always start non-fullscreen.
	fullscreen = !fullscreen;

	if ( fullscreen ) {
		SDL_SetWindowFullscreen( this->window, SDL_WINDOW_FULLSCREEN );
	}
	else {
		SDL_SetWindowFullscreen( this->window, 0 );
	}	
}

