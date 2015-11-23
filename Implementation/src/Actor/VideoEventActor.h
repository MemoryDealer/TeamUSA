// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file VideoEventActor.h
/// \brief Declares VideoEventActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa
{
// Create new Actor and derive from BaseActor.
   // Provide documentation, do so by starting with "///"
   ///
   /// \class VideoEventActor
   /// \brief Will display a texture and perform no action until clicked. The TextureID can be set to an invalid value during construction if no image needs to be displayed.
	class  VideoEventActor : public BaseActor
	{

	private:
		ActorEvent actorEvent;

	public:

		// Declare constructor and destructor...

		// Constructor.
		explicit VideoEventActor( Region region, int textureID, ActorEventType eventType, int eventValue, int layer );

		// Destructor.
		virtual ~VideoEventActor( void ) override; 

		///
		/// \brief Generates an ActorEvent when the actor's region is clicked. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
		virtual const ActorEvent onClick( Player& player ) override;

        ///
        /// \brief Generates an ActorEvent when the actor's region is hovered over. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
		virtual const ActorEvent onHover( Player& player ) override;

		///
		/// \brief Advances the actor one frame. 
		/// \param Player The player
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
		virtual const ActorEvent step( Player& player );
	};

}
