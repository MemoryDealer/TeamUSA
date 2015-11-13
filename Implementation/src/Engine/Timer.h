// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Timer.h
/// \brief Declares Timer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Headers.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {

    ///
    /// \class Timer
    /// \brief A timer that counts up from zero in milliseconds.
    class Timer final {

    public:

        explicit Timer( void );

        ~Timer( void );

        ///
        /// \brief Starts the timer.
        const uint32_t start( void );

        ///
        /// \brief Stops the timer.
        void stop( void );

        ///
        /// \brief Pauses the timer.
        void pause( void );

        ///
        /// \brief Unpauses the timer.
        void unpause( void );

        ///
        /// \brief Gets the time in milliseconds since the timer was started.
        /// \return The elapsed time.
        const uint32_t getTicks( void ) const;

    private:

        uint32_t mStartTicks;
        uint32_t mPauseTicks;
        bool mPaused;
        bool mStarted;

    };

}
