// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file AudioStreamActor.cpp
/// \brief Implements AudioStreamActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "AudioStreamActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace USA; // We want to use our namespace across this whole file.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

AudioStreamActor::AudioStreamActor(string path )
{
    // ...
    m_path = path;
    activated = false;
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

    activated = true;
    e.type = StreamAudio;
    return e;
}

std::string AudioStreamActor ::getPath(){
    return m_path;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
