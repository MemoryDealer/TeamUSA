// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file movingActor.h
/// \brief Declares movingActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa{
   // Create new Actor and derive from BaseActor.
   // Provide documentation, do so by starting with "///"
   ///
   /// \class movingActor
   /// \brief Will transition from one region to the next by calculating the distance to move each frame for a set number of frames.
   ///This allows for movement across the X and Y axis as well as scaling of the size of textures.
   ///If moveOnSpawn is set, then the step method will advance the actor immediately.
   ///Otherwise, the actor will move after it is clicked on.
	class movingActor : public  BaseActor {
		private:
		Region endRegion;
		int transitionSteps = 0;
		int currentStep = 0;
		int xSpeed = 0;
		int ySpeed = 0;
		bool isActive = false;

		public:
		// Declare constructor and destructor...

		// Constructor.
		explicit  movingActor( Region startRegion,Region endregion, int textureId,int layer, int transitionsteps, bool moveOnSpawn );

		// Destructor.
		virtual ~movingActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

		// Override onClick, onHover, and step, provide documentation.

		///
		/// \brief <Give description of what actor does on click>
		virtual const ActorEvent onClick( Player& player ) override;

		///
		/// \brief <Give description of what actor does on hover>
		virtual const ActorEvent onHover( Player& player ) override;

		///
		/// \brief <Give description of what happens each frame to this actor>
		virtual const ActorEvent step( Player& player ) override;

		// Declare additional functions here as specified in UML diagram.
	};
};
