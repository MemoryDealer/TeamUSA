// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file CursorStyle.h
/// \brief Declares CursorStyle enumerations.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {

    /// 
    /// \brief The possible styles for the mouse cursor.
    enum class CursorStyle {

        CURSOR_DEFAULT, ///< Default cursor.
        CURSOR_SELECT, ///< Offers the ability to select an object.
        CURSOR_LEFT, ///< Points left.
        CURSOR_RIGHT, ///< Points right.
        CURSOR_UP, ///< Points up.
        CURSOR_DOWN ///< Points down.

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //