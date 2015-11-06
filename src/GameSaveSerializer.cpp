// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file GameSaveSerializer.h
/// \brief Declares save file serializer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once
#include GameSaveSerializer.h
#include <vector>
#include <iostream>
#include <thread>

//--------

namespace USA {
	
	void GameSaveSerializer::load(int &levelID, int &sceneID, std::vector<int> &inventory){
		// Retrieve appropriate file
		
		// Read appropriate file contents
	}
	
	void GameSaveSerializer::save(int &levelID, int &sceneID, std::vector<int> &inventory){
		// create a new thread
		std::mutex threadLock;
		
		if(threadLock.try_lock()){
			std::thread saveThread(saveInThread, this, levelID, SceneID, inventory);
		}
		
		// merge back into main thread
		saveThread.detatch();
	}
	
	void GameSaveSerializer:saveInThread(int levelID, int sceneID, vector<int> inventory){
		// Write data to appropriate file
		
		// close file
	}
		
	}