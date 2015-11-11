// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file TextboxSpawnActor.cpp
/// \brief Declares TextboxSpawnActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "TextboxSpawnActor.h"


using namespace std;

namespace teamusa{
	std::string text="";


	TextboxSpawnActor::TextboxSpawnActor(Region region, std::string Text){
		// ...
		text=Text;
	}

	TextboxSpawnActor::~TextboxSpawnActor( void )
	{
	    // ...
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

	const ActorEvent TextboxSpawnActor::onClick( Player& player )
	{
	    // Handle clicking logic...

	    ActorEvent e;
	    // Assign data...
	    e.type=DisplayText;
	    return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

	const ActorEvent TextboxSpawnActor::onHover( Player& player )
	{
	    // Handle hovering logic...

	    ActorEvent e;
	    // Assign data...
	    return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

	const ActorEvent TextboxSpawnActor::step( Player& player )
	{
	    // Handle per-frame updates...

	    ActorEvent e;
	    // Assign data...
	    return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

	std::string TextboxSpawnActor::getText(void){
		return text;
	}

}



