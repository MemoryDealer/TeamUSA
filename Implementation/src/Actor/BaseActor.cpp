// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file BaseActor.h
/// \brief Implements BaseActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace USA;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

BaseActor::BaseActor( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

BaseActor::~BaseActor( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent BaseActor::onClick( Player& player )
{
    return ActorEvent();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const ActorEvent BaseActor::onHover( Player& player )
{
    return ActorEvent();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const bool BaseActor::isInBounds( const Point& point )
{
    // Test region...
    // ...

    return false;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //