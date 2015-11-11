#include <string>
#include "SDL2/SDL.h"
#include "ResourceGroup.hpp"
#include "Video/VideoEngine.hpp"
#include "Audio/AudioEngine.hpp"

using namespace teamusa;

void begin_test(){
  const int NUM_LAYERS = 7;
  const int WIDTH = 1280;
  const int HEIGHT = 720;
  const int NUM_TEXTURES = 7;
  const int SHADOW_LAYER = 4;
  TextureID textures[NUM_TEXTURES];
  Region regions[NUM_TEXTURES];
  VideoEngine vid("MyGameLongName", WIDTH, HEIGHT);
  AudioEngine audio;

  // Load audio
  audio.playStream("res/ambient.wav");
  audio.loadSound("res/key.wav", 1000, CORE_RESOURCE);

  // Init regions
  // background region is full screen.
  regions[0] = {0, 0, WIDTH, HEIGHT};
  for(int i=1;i<NUM_LAYERS;++i){
    if(i == SHADOW_LAYER) continue;
    regions[i] = {10, 10, (7-i)*80, (7-i)*60};
  }
  // light in shadow region must be larger to show effect
  regions[SHADOW_LAYER] = {0, 0, 512, 512};

  // Load textures
  std::string temp;
  for(int i=0;i<NUM_LAYERS;++i){
    temp = "";
    temp += "res/" + std::to_string(i) + ".png";
    textures[i] = 1000 + i;
    vid.loadTexture(temp, textures[i], CORE_RESOURCE);
  }

  // Show textbox
  std::string spookyText = "Spooky text is very spooky. 2Spooky4Me.";
  vid.showTextbox(spookyText);

  // Main loop
  bool quit = false;
  SDL_Event e;
  while(!quit){
    // Change texture position
    for(int i=1; i<NUM_TEXTURES; ++i){
      if(i == SHADOW_LAYER) continue;
      regions[i].y = (regions[i].y + 1) % (HEIGHT-regions[i].h);
    }
    // Draw textures
    for(int i=0; i<NUM_LAYERS; ++i){
      vid.render(regions[i], i, textures[i]);
    }
    // Handle events
    while(SDL_PollEvent(&e)){
      // Exit when user clicks on X
      if (e.type == SDL_QUIT){
        quit = true;
        break;
      }
      // Toggle textbox on click
      else if (e.type == SDL_MOUSEBUTTONDOWN){
        if(vid.isShowingTextbox())
          vid.hideTextbox();
        else
          vid.showTextbox(spookyText);
        audio.playSound(1000);
      }
    }
    // Set light destination to the mouse coordinates.
    SDL_GetMouseState(&regions[SHADOW_LAYER].x, &regions[SHADOW_LAYER].y);
    // Center light on cursor
    regions[SHADOW_LAYER].x -= regions[SHADOW_LAYER].w/2;
    regions[SHADOW_LAYER].y -= regions[SHADOW_LAYER].h/2;
    // Display final result
    vid.display();
    // Sleep 16.67ms ~60fps
    SDL_Delay(16.67);
  }
  vid.deleteResourceGroup(LEVEL_RESOURCE);
  vid.deleteResourceGroup(CORE_RESOURCE);
}

int main(void){
  begin_test();
  SDL_Quit();
  return 0;
}
