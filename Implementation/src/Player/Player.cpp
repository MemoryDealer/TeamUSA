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
const int Player::CURSOR_DEFAULT_ID = 1667;
const int Player::CURSOR_SELECT_ID = 1668;
const int Player::CURSOR_UP_ID = 1669;
const int Player::CURSOR_DOWN_ID = 1670;
const int Player::CURSOR_LEFT_ID = 1671;
const int Player::CURSOR_RIGHT_ID = 1672;
const int Player::MOUSE_CLICK_ID = 1700;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Player::Player( void )
: mRegion( )
, mLayer( 4 )
, mTextureID( 0 )
, mPosition( )
, mInventory( )
, mCursorStyle( CursorStyle::CURSOR_DEFAULT )
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

const int Player::getCursorTextureID( void ) const
{
    switch ( mCursorStyle ) {
    default: case CursorStyle::CURSOR_DEFAULT: 
        return CURSOR_DEFAULT_ID;

    case CursorStyle::CURSOR_SELECT:
        return CURSOR_SELECT_ID;

    case CursorStyle::CURSOR_UP:
        return CURSOR_UP_ID;

    case CursorStyle::CURSOR_DOWN:
        return CURSOR_DOWN_ID;

    case CursorStyle::CURSOR_LEFT:
        return CURSOR_LEFT_ID;

    case CursorStyle::CURSOR_RIGHT:
        return CURSOR_RIGHT_ID;
    }
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

const Player::Inventory& Player::getInventory() const
{
    return mInventory;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Player::setInventory( const Inventory& inventory )
{
    mInventory.clear();
    mInventory = inventory;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //