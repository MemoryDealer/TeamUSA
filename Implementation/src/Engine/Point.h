// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Point.h
/// \brief Declares Point struct.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include <stdint.h>

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {

	///
	/// \class Point
	/// \brief An (x,y) coordinate within the rendering window.
    struct Point {
        int32_t x, y;

        Point( void ) : x( 0 ), y( 0 ) { }
        Point( int32_t x, const int32_t y ) : x( x ), y( y ) { }
    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
