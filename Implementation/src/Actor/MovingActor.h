// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file MovingActor.h
/// \brief Declares MovingActor class.
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
   /// \class MovingActor
   /// \brief Will transition from one region to the next by calculating the distance to move each frame for a set number of frames.
   /// This allows for movement across the X and Y axis as well as scaling of the size of textures.

	class MovingActor : public  BaseActor {
		private:
		Region endRegion;
		int transitionSteps = 1;
		int currentStep = 0;
		int xSpeed = 0;
		int ySpeed = 0;
		int hGrowth = 0;
		int wGrowth = 0;
		bool isActive = false;
		

		public:
		// Declare constructor and destructor...

		// Constructor.
		explicit  MovingActor( Region startRegion,Region endregion, int textureId,int layer, int transitionsteps, bool moveOnSpawn );

		// Destructor.
		virtual ~MovingActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

		// Override onClick and step, provide documentation.

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
