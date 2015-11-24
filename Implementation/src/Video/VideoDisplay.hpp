/**
 * @file VideoDisplay.hpp
 * @brief Declares the VideoDisplay class
 */

#include <stdexcept>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#ifndef MWRAP_VIDEODISPLAY_H
#define MWRAP_VIDEODISPLAY_H

namespace mediawrap {
  /**
   * @class VideoDisplay
   * Creates a window and initializes SDL2 and SDL2_IMG.
   * Must be destroyed after use.
   */
  class VideoDisplay{
    private:
      SDL_Window* window;
    public:
      /**
        * Attempts to init SDL2 and SDL2_IMG and create a window.
        * Throws runtime_error if unable to set up any of these.
        * @param title
        *   The title to display at the top of the window.
        * @param width
        *   The width of the window created.
        * @param height
        *   The height of the window created.
        */
      VideoDisplay(const std::string& title, unsigned int width, unsigned int height);
    
      /**
        * Destroys the window and renderer. Uninitializes SDL and SDL_Image.
        */
      ~VideoDisplay(void);
    
      /**
        * Creates a renderer attached to this window.
        * Must be deleted after use.
        * @return
        *   An SDL2 renderer for this window.
        */
      SDL_Renderer* get_renderer(void);

	  /*
	   * Switches the window from windowed to fullscreen if windowed, and from fullscreen
	   * to windowed if in fullscreen mode.
	   */
	  void swapFullscreen( void );
  };
}
#endif /*MWRAP_VIDEODISPLAY_H*/
