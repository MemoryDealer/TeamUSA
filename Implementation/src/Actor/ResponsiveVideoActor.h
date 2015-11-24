// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file ResponsiveVideoActor.h
/// \brief Declares ResponsivevideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa{
	///
	/// \class ResponsiveVideoActor
	/// \brief Changes its texture ID based on hovering and clicks.
	class  ResponsiveVideoActor : public BaseActor{
	private:
		int hoverTexture;
		int clickTexture;
		int defaultTextureId;


	public:
		 // Declare constructor and destructor...

		 // Constructor.
		 explicit ResponsiveVideoActor( Region region, int hoverTextureId, int clickTextureID, int defaulTextureID,int layer );

		 // Destructor.
		 virtual ~ResponsiveVideoActor( void ) override; 

		///
		/// \brief Generates an ActorEvent when the actor's region is clicked. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
		 virtual const ActorEvent onClick( Player& player ) override;
        ///
        /// \brief Generates an ActorEvent when the actor's region is hovered over. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action
		 virtual const ActorEvent onHover( Player& player ) override;

		///
		/// \brief Advances the actor one frame. 
		/// \param Player The player
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
		 virtual const ActorEvent step(Player& player) override;

		 ///
		 /// \brief Sets the reqeusted texture ID
		 /// \param TextureID The integer ID of the requested texture. 
		 void setTextureId(int TextureId);
	};
}
