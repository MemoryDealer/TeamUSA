// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file BaseActor.h
/// \brief Implements BaseActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "BaseActor.h"

#include "Engine/Point.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

BaseActor::BaseActor( void )
: mRegion( )
, mVideo( )
, mAudioID( -1 )
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
    // Test horizontal.
    if ( point.x >= mRegion.x && point.x <= ( mRegion.x + mRegion.w ) ) {
        // Test vertical.
        if ( point.y >= mRegion.y && point.y <= ( mRegion.y + mRegion.h ) ) {
            return true;
        }
    }

    return false;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void BaseActor::setRegion( const Region& region )
{
    mRegion = region;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Region BaseActor::getRegion( void ) const
{
    return mRegion;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const int32_t BaseActor::getLayer( void ) const
{
    return mVideo.layer;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const int32_t BaseActor::getTextureID( void ) const
{
    return mVideo.textureID;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
