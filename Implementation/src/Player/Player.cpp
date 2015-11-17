// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file Player.cpp
/// \brief Implements Player class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Player.h"

#include "Engine/Assert.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace teamusa;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const int Player::FLASHLIGHT_ID = 1666;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Player::Player( void )
: mRegion( )
, mLayer( 4 )
, mTextureID( 0 )
, mPosition( )
, mInventory( )
, mCursorStyle( CursorStyle::CURSOR_NONE )
{
    mRegion = { 0, 0, 512, 512 };
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Player::~Player( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const bool Player::hasItem( const int32_t itemType ) const
{
    for ( auto& i : mInventory ) {
        if ( i == itemType ) {
            return true;
        }
    }
    
    return false;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Player::addItem( const int32_t itemType )
{
    mInventory.push_back( itemType );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Player::setCursor( const CursorStyle style )
{
    mCursorStyle = style;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Player::setPosition( const int32_t x, const int32_t y )
{
    mPosition.x = x;
    mPosition.y = y;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Player::setPosition( const Point& position )
{
    mPosition = position;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Point Player::getPosition( void ) const
{
    return mPosition;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //