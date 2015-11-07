// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file GameSaveSerializer.h
/// \brief Declares save file serializer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once
#include "GameSaveSerializer.h"
#include <vector>
#include <iostream>
#include <thread>

//--------

namespace USA {
	
	GameSaveSerializer::GameSaveSerializer(void)
	{
		
	}
	
	GameSaveSerializer::~GameSaveSerializer(void)
	{
		
	}
	
	void GameSaveSerializer::load(int &levelID, int &sceneID, std::vector<int> &inventory)
	{
		
		// Retrieve appropriate file
		std::ifstream inputFile;
		inputFile.open("save.bin", std::ios::binary | std::ios::in);
		
		// Read appropriate file contents
		// Read the level ID
		inputFile.read(levelID, sizeof(int));
		
		// Read the scene ID
		inputFile.read(sceneID, sizeof(int));
		
		// Read the inventory size
		inputFile.read(inventory.push_back(), sizeof(int));
		
		// Read the inventory contents
		while (!inputFile.eof())
		{
			inputFile.read(inventory.push_back(), sizeof(int));
		}
		// close file
		inputFile.close();
	}
	
	void GameSaveSerializer::save(int &levelID, int &sceneID, std::vector<int> &inventory)
	{
		// Launch the new thread and intiaite save
		std::thread saveThread(saveInThread, this, levelID, SceneID, inventory);
		saveThread.detatch();
	}
	
	void GameSaveSerializer::saveInThread(int levelID, int sceneID, std::vector<int> inventory)
	{
		// Lock the thread
		GameSaveSerializer::fileLock.lock();
		
		//Open the approriate data stream
		std::ofstream outputFile;
		outputFile.open("save.bin", std::ios::binary | std::ios::out);
		
		// Write data to appropriate file
		// Write the level ID
		outputFile.write(&levelID, sizeof(int));
		
		// Write the scene ID
		outputFile.write(&sceneID, sizeof(int));
		
		// Write the inventory size
		outputFile.write(inventory.size(), sizeof(int));
		
		// Write each inventory item (as an integer representation) to the file
		for(auto iter = inventory.begin(); iter != inventory.end(); ++iter)
		{
			outputFile.write(iter*, sizeof(int));
		}
		
		// close file
		outputFile.close();
		
		// Unlock
		GameSaveSerializer::fileLock.unlock();
	}
		
}