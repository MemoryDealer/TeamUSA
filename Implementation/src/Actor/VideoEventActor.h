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
		explicit VideoEventActor( Region region, int textureID, ActorEventType eventType, int eventValue, int defaultTextureID, int layer );

		// Destructor.
		virtual ~VideoEventActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

		// Override onClick, onHover, and step, provide documentation.

		///
		/// \brief The onClick method will return the ActorEventType and value given to this actor during construction time.
		///  Can be used to cause LoadGame and SaveGame events.
		virtual const ActorEvent onClick( Player& player ) override;

		///
		/// \brief The onHover method will set the player's cursor style to CURSOR_SELECT.
		virtual const ActorEvent onHover( Player& player ) override;
	};

};
