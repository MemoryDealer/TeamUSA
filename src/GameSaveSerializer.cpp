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
		ifstream inputFile;
		inputFile.open("save.bin", ios::binary | ios::in);
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
		//Open the approriate data stream
		ofstream outputFile
		outputFile.open("save.bin", ios::binary | ios::out);
		// Write data to appropriate file
		outputFile.write(&levelID, sizeof(int));
		outputFile.write(&sceneID, sizeof(int));
		outputFile.write(inventory.size(), sizeof(int));
		outputFile.write(inventory, sizeof(inventory));
		// close file
		outputFile.close();
	}
		
	}