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
		 virtual ~ResponsiveVideoActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

		 // Override onClick and onHover, provide documentation.

		 ///
		 /// \brief When onClick is called, the onClick texture will be set permanently. Can disappear or appear by utilizing an invalid TextureID.
		 virtual const ActorEvent onClick( Player& player ) override;

		 ///
		 /// \brief When onHover is called, it will display the hover TextureID.
		 virtual const ActorEvent onHover( Player& player ) override;

		 ///
		 /// \brief does nothing.
		 virtual const ActorEvent step(Player& player) override;

		 // Declare additional functions here as specified in UML diagram.
		 void setTextureId(int TextureId);
	};
};
