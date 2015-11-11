// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Player.h
/// \brief Declares Player class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Headers.h"

#include "CursorStyle.h"
#include "Engine/Point.h"
#include "Video/VideoEngine.hpp"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace teamusa {

    class Player final
    {

    public:

        explicit Player( void );

        ~Player( void );

        const bool hasItem( const int32_t itemType ) const;

        void addItem( const int32_t itemType );

        void setCursor( const CursorStyle style );

        void setPosition( const int32_t x, const int32_t y );

        const Point getPosition( void ) const;

    private:

        Region mRegion;
        int32_t mLayer;
        int32_t mTextureID;
        Point mPosition;
        std::vector<int32_t> mInventory;
        CursorStyle mCursorStyle;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //