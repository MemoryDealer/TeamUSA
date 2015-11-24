// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
//
// Author: Vincent Sanchez
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file GameSaveSerializer.h
/// \brief Declares save file serializer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once
#include <vector>
#include <fstream>
#include <mutex>
#include <string>
#include <thread>

#include "Player/Player.h"

//--------

namespace teamusa {
	
	///
    /// \class GameSaveSerializer
    /// \brief Provides multithreaded save, single-thread load of save files.
	class GameSaveSerializer {
		private:
			std::mutex fileLock;
            int32_t slot;
		public:

            GameSaveSerializer(void);

            ~GameSaveSerializer(void);

            ///
            /// \brief Sets the slot number to save/load in.
            void setSlot( const int32_t slot );

			///
			/// \brief Loads a save file
            /// \return True if save file was loaded successfully, false if it doesn't exist.
			bool load(int &levelID, int &sceneID, Player::Inventory &inventory);
				
			///
			/// \brief Saves a file
			void save(const int &levelID, const int &sceneID, const Player::Inventory &inventory);
				
			///
			/// \brief Saves a file in a separate thread. 
			void saveInThread(const int levelID, const int sceneID, const Player::Inventory inventory);
	};
}