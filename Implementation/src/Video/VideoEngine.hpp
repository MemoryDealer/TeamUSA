/**
 * @file VideoEngine.hpp
 * @brief Declares the VideoEngine class
 */

#include <stdexcept>
#include <string>
#include <vector>
#include "VideoContext.hpp"
#include "Engine/ResourceGroup.hpp"
#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

namespace teamusa {

  using mediawrap::VideoContext;
  typedef mediawrap::VideoContext::TextureID TextureID;
  typedef mediawrap::VideoContext::Region Region;

  /**
   * @class VideoEngine
   * Provides video capabilities that are specific to Legend of the Great Unwashed.
   * Utilizes VideoContext to perform rendering.
   */
  class VideoEngine{
    private:
      static const unsigned int NUM_LAYERS = 7;
      static const unsigned int SHADOW_LAYER = 4;
      static const TextureID TEXT_LAYER = 8;
      static const TextureID MAX_RESERVED_ID = 1000;
      bool textboxActive;
      TextureID layers[NUM_LAYERS];
      std::vector<TextureID> coreResources;
      std::vector<TextureID> levelResources;
      VideoContext *videoContext;
      Region textboxPadding;
      Region textboxRegion;

      /**
       * Clears all layers with the default clear color. Does not modify the
       * textbox layer.
       */
      void clearLayers();
    public:

      /**
       * Creates a new window that provides basic 2D drawing capabilities.
       * @param title
       *  The title to be displayed at the top of the window.
       * @param width
       *  The width of the window in pixels.
       * @param height
       *  The height of the window in pixels.
       */
      VideoEngine(
       const std::string &title, unsigned int width, unsigned int height);
      
      /**
       * Destroys the video engine after freeing all associated textures.
       */
      ~VideoEngine();

      /**
       * Loads the image file from the given path, transforms it into a
       * surface, and pushes it onto the graphics card as a texture.
       * @param path
       *  The relative location of the image to load.
       * @param id
       *  The id to assign to the loaded texture.
       * @param resGroup
       *  The group to load the resource into.
       */
      void loadTexture(const std::string &path, TextureID id, ResourceGroup group);

      /**
       * Renders the texture onto the given layer in the given region.
       * @param region
       *  The region to draw the texture into.
       * @param layer
       *  The layer to render the image onto (0-6) are valid.
       * @param id
       *  The id of the texture to draw.
       */
      void render(const Region &region, const unsigned int layer, const TextureID id);

      
      void renderDebugBox( const Region& region, 
                           const VideoContext::DebugColor = VideoContext::DebugColor::BLUE );

      /**
       * Renders the texture onto the given layer in the given region with the
       * given rotation angle.
       * @param region
       *  The region to draw the texture into.
       * @param layer
       *  The layer to render the image onto (0-6) are valid.
       * @param id
       *  The id of the texture to draw.
       * @param angle
       *  The angle in degrees to rotate the image. Defaults to 0.
       */
      void renderRotate(
       Region &region, unsigned int layer, TextureID id, float angle = 0.0);

	  /**
	   * Calls swapFullscreen() on VideoDisplay.
	   */
	  void swapFullscreen( void );

      /**
       * States whether a textbox is currently being displayed or not.
       * @return
       *  The status of the textbox.
       */
      bool isShowingTextbox();

      /**
       * Displays the given text in a textbox.
       * @param text
       *  The text to display on screen.
       */
      void showTextbox(const std::string &text);

      /**
       * Clears the current textbox so it does not appear.
       */
      void hideTextbox();

      /**
       * Removes the current texture from graphics memory.
       * @param id
       *  The id of the texture to delete.
       */
      void deleteTexture(TextureID id);
      
      /**
       * Deletes all textures associated with the given resource group.
       * @param resourceGroup
       *  The group of textures to delete from video memory.
       */
      void deleteResourceGroup(ResourceGroup resourceGroup);
      
      /**
       * Displays all rendered textures on screen.
       */
      void display();
  };
}
#endif /*VIDEOENGINE_H*/
