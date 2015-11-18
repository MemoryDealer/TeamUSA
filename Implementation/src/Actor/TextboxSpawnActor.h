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

		public:
		// Declare constructor and destructor...

		// Constructor.
		explicit TextboxSpawnActor(Region region, std::string text);

		// Destructor.
		virtual ~TextboxSpawnActor( void );

		// Override onClick, onHover, and step, provide documentation.

		///
		/// \brief return a display text actor event
		virtual const ActorEvent onClick( Player& player );

		///
		/// \brief Override.
		virtual const ActorEvent step( Player& player );
	

		// Declare additional functions here as specified in UML diagram.
		///
		/// \brief Retrurn the text when called.
		std::string getText(void);

	};	
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
