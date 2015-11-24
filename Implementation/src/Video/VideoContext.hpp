/**
 * @file VideoContext.hpp
 * @brief Declares the VideoContext class
 */

#include <unordered_map>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "VideoDisplay.hpp"

#ifndef MWRAP_VIDEOCONTEXT_H
#define MWRAP_VIDEOCONTEXT_H

namespace mediawrap {

  /**
   * @class VideoContext
   * Provides basic 2D rendering capabilities. Acts as an abstraction layer to the SDL2 video library.
   *
   */
  class VideoContext {
    public:

      /**
       * Used to specify x, y, width, height of an texture source or
       * destination region.
       */
      typedef SDL_Rect Region;

      /**
       * Used to identify each texture uniquely. Each texture loaded is
       * to be assigned a key of this type.
       */
      typedef unsigned int TextureID;

      /**
       * Used to access elements in the texture map.
       */
      typedef std::unordered_map<TextureID, SDL_Texture*>::iterator texture_iter;

      /**
       * Used to designate how an image should be flipped across an axis.
       * These two values can be ORed together to achive both effects.
       */
      enum Flip {
        FLIP_NONE = SDL_FLIP_NONE,
        FLIP_HORIZONTAL = SDL_FLIP_HORIZONTAL,
        FLIP_VERTICAL = SDL_FLIP_VERTICAL
      };

      /**
       * Used to specify how a texture should behave when objects are rendered
       * onto it.
       */
      enum BlendMode {
        BLENDMODE_NONE = SDL_BLENDMODE_NONE,
        BLENDMODE_BLEND = SDL_BLENDMODE_BLEND,
        BLENDMODE_ADD = SDL_BLENDMODE_ADD,
        BLENDMODE_MOD = SDL_BLENDMODE_MOD
      };

      enum DebugColor {
          RED = 0,
          GREEN,
          BLUE
      };

      /**
       * Constructs a new rendering context that includes a window and the
       * renderer associated with it. Provides utilities for loading textures
       * and storing them in an internal mapping.
       * @param title
       *   The title to display at the top of the window.
       * @param width
       *   The width of the window created.
       * @param height
       *   The height of the window created.
       */
      VideoContext(
       const std::string& title, unsigned int width, unsigned int height);

      /**
       * Deletes the renderer and window associated with this context. Also
       * deletes all textures currently loaded by this context.
       */
      ~VideoContext(void);

      /**
       * Displays the rendered textures on screen.
       */
      void display(void);

      /**
       * Loads a texture from the filename into the specified texture id.
       * Must be deleted using delete_texture.
       * @param id
       *   The id to assign to this texture. If this id is already in use,
       *   it deletes the existing texture first before loading this new one.
       * @param image_path
       *   The path of the file to load as a texture.
       * @param blend
       *   The blending mode which decides how to react with other textures.
       *   Defaults to BLENDMODE_BLEND.
       * @return
       *   The auto-detected source rectangle for this image.
       */
      Region load_texture(TextureID id, const std::string& image_path,
       BlendMode blend = BLENDMODE_BLEND);

      /**
       * Creates a blank texture, which should be filled completely or
       * cleared before rendering to prevent old fragments from appearing.
       * Must be deleted using delete_texture.
       * @param id
       *   The id to assign to this texture. If this id is already in use,
       *   it deletes the existing texture first before loading this new one.
       * @param width
       *   The width of the new texture
       * @param height
       *   The height of the next texture
       * @param blend
       *   The blending mode which decides how to react with other textures.
       *   Defaults to BLENDMODE_BLEND.
       * @return
       *   The source region of the new texture created.
       */
      Region create_texture(TextureID id,
       int width, int height,
       BlendMode blend = BLENDMODE_BLEND);

      /**
       * The deletes the given texture from this context.
       * @param id
       *   The id of the texture to delete.
       */
      void delete_texture(TextureID id);
    
      /**
       * Draws the given texture onto the canvas.
       * @param id
       *   The id of the texture to draw onto the canvas.
       * @param dest
       *   The destination region to draw onto the canvas.
       * @param src
       *   The source region to copy from when drawing.
       */
      void render(TextureID id, Region* dest, Region* src);

      void renderDebugBox( const Region& region, 
                           const DebugColor color,
                           const TextureID layer );

      /**
       * Draws the given source texture onto the destination texture.
       * @param dest_id
       *   The id of the texture that will act as a canvas and be drawn on.
       * @param src_id
       *   The id of the texture to draw over the destination Texture.
       * @param dest_region
       *   The region to draw the source texture into.
       * @param src_region
       *   The region to copy the source texture from.
       */
      void render_onto(TextureID dest_id, TextureID src_id,
       const Region* dest_region, Region* src_region);

      /**
       * Draws the given source texture onto the destination texture after
       * applying a rotate and flip operation.
       * @param dest_id
       *   The id of the texture that will act as a canvas and be drawn on.
       * @param src_id
       *   The id of the texture to draw over the destination Texture.
       * @param dest_region
       *   The region to draw the source texture into.
       * @param src_region
       *   The region to copy the source texture from.
       * @param angle
       *   The angle in degrees to rotate the source image. Defaults to zero.
       * @param flip
       *   The direction to flip the source texture in. Defaults to none.
       */
      void render_rotate(TextureID dest_id, TextureID src_id,
       Region* dest_region, Region* src_region,
       double angle=0.0, Flip flip=FLIP_NONE);
    
      /**
       * Clears the canvas with the default clear color.
       */
      void render_clear();

      /**
       * Clears the given texture with the default clear color.
       * @param id
       *   The id of the texture to clear.
       */
      void render_clear(TextureID id);

      /**
       * Fills the given texture with the given rgba value.
       * @param id
       *   The id of the texture to fill with the specified color.
       * @param r
       *   The red value 0-255
       * @param g
       *   The green value 0-255
       * @param b
       *   The blue value 0-255
       * @param a
       *   The alpha value 0-255
       */
      void fill_texture(TextureID id, int r, int g, int b, int a);

      /**
       * Loads the given font from the path specified. Only one font may be
       * loaded at any given time. Repeated calls to this function will delete
       * the previous font before creating a new one.
       * @param font_path
       *   The path to the ttf file to load as a font.
       * @param font_size
       *   The size of the font to load.
       */
      void load_font(const std::string& font_path, int font_size);
      
      /**
       * Renders the given text onto the the destination texture.
       * A successful call to load_font must be performed before this method
       * should be called.
       * @param dest_id
       *   The destination texture to render onto.
       * @param dest_region
       *   The region on the destination texture to render the font into.
       * @param text
       *   The string to render.
       * @param r
       *   The red value 0-255
       * @param g
       *   The green value 0-255
       * @param b
       *   The blue value 0-255
       * @param a
       *   The alpha value 0-255
       */
      void render_text(TextureID dest_id, Region* dest_region,
       const std::string& text, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	  /**
	   * Checks the state of the window and swaps to fullscreen or windowed mode.
	   */
	  void swapFullscreen( void );

    private:
      std::unordered_map<TextureID, SDL_Texture*> *textures;
      VideoDisplay* video_display;
      SDL_Renderer* renderer;
      TTF_Font* font;
  };
}
#endif /*MWRAP_VIDEOCONTEXT_H*/
