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

    ///
    /// \class Player
    /// \brief Handles all data relevant to the player engaging the game.
    class Player final
    {

    public:

		///
		/// Player inventory - an array of integer IDs.
        typedef std::vector<int32_t> Inventory;

    public:

        explicit Player( void );

        ~Player( void );

        ///
        /// \brief Tests if the player has an item in their inventory.
        /// \param itemType The item type identifier.
        /// \return True if the player has the item.
        const bool hasItem( const int32_t itemType ) const;

        ///
        /// \brief Inserts an item into the player's inventory.
        /// \param itemType The item identifier to insert.
        void addItem( const int32_t itemType );

        ///
        /// \brief Sets the visual style of the player's mouse cursor.
        /// \param style The style type for the cursor.
        void setCursor( const CursorStyle style );

        ///
        /// \brief Returns the current cursor texture ID associated with the 
        ///     cursor style.
        const int getCursorTextureID( void ) const;

        ///
        /// \brief Sets the position of the player's cursor.
        /// \param x The x-coordinate of the cursor.
        /// \param y The y-coordinate of the cursor.
        void setPosition( const int32_t x, const int32_t y );

        ///
        /// \brief Sets the position of the player's cursor.
        /// \param position A Point struct containing the cursor position.
        void setPosition( const Point& position );

        ///
        /// \brief Gets the player's cursor position.
        /// \return A Point struct containing the cursor position.
        const Point getPosition( void ) const;

        ///
        /// \brief Returns the player's inventory.
        const Inventory& getInventory() const;

        ///
        /// \brief Clears the player's current inventory and assigns the new one.
        /// \param inventory The inventory to assign to the player.
        void setInventory( const Inventory& inventory );

        static const int FLASHLIGHT_ID;
        static const int CURSOR_DEFAULT_ID;
        static const int CURSOR_SELECT_ID;
        static const int CURSOR_UP_ID;
        static const int CURSOR_DOWN_ID;
        static const int CURSOR_LEFT_ID;
        static const int CURSOR_RIGHT_ID;
        static const int MOUSE_CLICK_ID;

    private:

        Region mRegion;
        int32_t mLayer;
        int32_t mTextureID;
        Point mPosition;
        Inventory mInventory;
        CursorStyle mCursorStyle;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //