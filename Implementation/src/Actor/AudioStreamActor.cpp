// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file AudioStreamActor.cpp
/// \brief Implements AudioStreamActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "AudioStreamActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

AudioStreamActor::AudioStreamActor(std::string path )
: BaseActor( )
{
    // ...
    this->path = path;
    this->activated = false;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

AudioStreamActor::~AudioStreamActor( void)

{
    // ...
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

const ActorEvent AudioStreamActor::step( Player& player )
{
    // Handle per-frame updates...

    ActorEvent e;
    // Assign data...
    //if(!this->activated){
        e.type = StreamAudio;
    //}
    return e;
}

std::string AudioStreamActor ::getPath(){
    return this->path;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
