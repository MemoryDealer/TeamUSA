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
#include <thread>

//--------

namespace teamusa {
	
	///
    /// \class GameSaveSerializer
    /// \brief Provides multithreaded save, single-thread load of save files.
	class GameSaveSerializer {
		private:
			std::mutex fileLock;
		public:

            GameSaveSerializer(void);

            ~GameSaveSerializer(void);

			///
			/// \brief Loads a save file
			void load(int &levelID, int &sceneID, std::vector<int> &inventory);
				
			///
			/// \brief Saves a file
			void save(int &levelID, int &sceneID, std::vector<int> &inventory);
				
			///
			/// \brief Saves a file in a separate thread. 
			void saveInThread(int levelID, int sceneID, std::vector<int> inventory);
	};
}