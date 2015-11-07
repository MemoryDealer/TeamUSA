// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file GameSaveSerializer.h
/// \brief Declares save file serializer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once
#include <vector>
#include <iostream>
#include <thread>

//--------

namespace USA {
	
	///
    /// \class GameSaveSerializer
    /// \brief Provides multithreaded save, single-thread load of save files.
	class GameSaveSerializer {
		private:
			std::mutex fileLock;
		public:
			///
			/// \brief Loads a save file
			void load(int &levelID, int &sceneID, std::vector<int> &inventory);
				
			///
			/// \brief Saves a file
			void save(int &levelID, int &sceneID, std::vector<int> &inventory);
				
			///
			/// \brief Saves a file in a separate thread. 
			void saveInThread(int levelID, int sceneID, std::vector<int> inventory);
	}
}