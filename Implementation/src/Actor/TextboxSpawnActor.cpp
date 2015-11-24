// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file TextboxSpawnActor.cpp
/// \brief Implements TextboxSpawnActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "TextboxSpawnActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa;
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

TextboxSpawnActor::TextboxSpawnActor(Region region, std::string Text)
: BaseActor( region ), activated( false )
{
	// ...
	text=Text;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
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
    if ( !activated ) {
        e.type = DisplayText;
        activated = true;
    }
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

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //



