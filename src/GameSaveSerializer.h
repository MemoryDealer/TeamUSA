// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file GameSaveSerializer.h
/// \brief Declares save file serializer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

//--------

namespace USA {
	
	///
    /// \class GameSaveSerializer
    /// \brief Provides multithreaded save, single-thread load of save files.
	class GameSaveSerializer {
		private:
			int levelID;
			int sceneID;
			vector<int> inventory;
			
		public:
			///
			/// \brief Loads a save file
			void load();
				
			///
			/// \brief Saves a file
			void save();
				
			///
			/// \brief Saves a file in a separate thread. 
			void saveInThread();
	}
}