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
   /// \class ExampleActor
   /// \brief <Give brief description here>
class TextboxSpawnActor{
	private:
	std::string text;

	public:
	// Declare constructor and destructor...

	// Constructor.
	explicit TextboxSpawnActor(Region region, std::string text);

	// Destructor.
	virtual ~TextboxSpawnActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

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

	std::string getText(void);
	};
};
