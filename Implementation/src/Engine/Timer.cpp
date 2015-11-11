// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Timer.cpp
/// \brief Implements Timer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Engine/Timer.h"

#include <SDL2/SDL.h>

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Timer::Timer( void )
: mStartTicks( 0 )
, mPauseTicks( 0 )
, mPaused( false )
, mStarted( false )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Timer::~Timer( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const uint32_t Timer::start( void )
{
    mStarted = true;
    mPaused = false;

    mStartTicks = SDL_GetTicks();
    return mStartTicks;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Timer::stop( void )
{
    mStarted = mPaused = false;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Timer::pause( void )
{
    if ( mStarted && !mPaused ) {
        mPaused = true;
        mPauseTicks = SDL_GetTicks() - mStartTicks;
    }
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Timer::unpause( void )
{
    if ( mPaused ) {
        mPaused = false;
        mStartTicks = SDL_GetTicks() - mPauseTicks;
        mPauseTicks = 0;
    }
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const uint32_t Timer::getTicks( void ) const
{
    if ( mStarted ) {
        return (mPaused) ? mPauseTicks :
            (SDL_GetTicks() - mStartTicks);
    }

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //