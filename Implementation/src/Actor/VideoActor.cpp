// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file VideoActor.cpp
/// \brief Implements VideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "VideoActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

VideoActor::VideoActor( Region region, int textureId  = -1, int layer = 1 )
: BaseActor( region )
{
    this->mVideo = new ActorVideo;
    this->mVideo->textureID = textureId;
    this->mVideo->layer = layer;
    this->mRegion = region;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

VideoActor::~VideoActor( void)
{
    delete this->mVideo;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
const ActorEvent VideoActor::step( Player& player )
{
    ActorEvent e;
    return e;
}
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
