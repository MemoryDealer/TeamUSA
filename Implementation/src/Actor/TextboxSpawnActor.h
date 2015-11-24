// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file TextboxSpawnActor.h
/// \brief Declares TextboxSpawnActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"
#include <string>

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa{

   // Create new Actor and derive from BaseActor.
   // Provide documentation, do so by starting with "///"
   ///
   /// \class TextboxSpawnActor
   /// \brief Will emit a DisplayText event when the onClick method is called. 
   /// The actor can then have its text accessed by the engine for display through a call to the getText method.

	class TextboxSpawnActor : public BaseActor
	{
		private:
		std::string text;
        bool activated;

		public:
		// Declare constructor and destructor...

		// Constructor.
		explicit TextboxSpawnActor(Region region, std::string text);

		// Destructor.
		virtual ~TextboxSpawnActor( void );

		///
		/// \brief Generates an ActorEvent when the actor's region is clicked. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
		virtual const ActorEvent onClick( Player& player );

        ///
        /// \brief Generates an ActorEvent when the actor's region is hovered over. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
		virtual const ActorEvent step( Player& player );
		
		///
		/// \brief Retrieves the text for the textbox from the level file. 
		std::string getText(void);

	};	
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
