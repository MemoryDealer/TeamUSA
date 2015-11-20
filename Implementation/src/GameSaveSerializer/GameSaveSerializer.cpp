// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
//
// Author: Vincent Sanchez
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file GameSaveSerializer.h
/// \brief Declares save file serializer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "GameSaveSerializer.h"

//--------

namespace teamusa {
	
	GameSaveSerializer::GameSaveSerializer(void)
    : fileLock()
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
		inputFile.read(reinterpret_cast<char*>(levelID), sizeof(int));
		
		// Read the scene ID
		inputFile.read(reinterpret_cast<char*>(sceneID), sizeof(int));
		
		// Read the inventory contents
		while (!inputFile.eof())
		{
            int item = 0;
			inputFile.read(reinterpret_cast<char*>(item), sizeof(int));
            inventory.push_back( item );
		}
		// close file
		inputFile.close();
	}
	
	void GameSaveSerializer::save(int &levelID, int &sceneID, std::vector<int> &inventory)
	{
		// Launch the new thread and intiaite save
		std::thread saveThread(&GameSaveSerializer::saveInThread, this, levelID, sceneID, inventory);
		saveThread.detach();
	}
	
	void GameSaveSerializer::saveInThread(int levelID, int sceneID, std::vector<int> inventory)
	{
		// Lock the thread
		fileLock.lock();
		
		//Open the approriate data stream
		std::ofstream outputFile;
		outputFile.open("save.bin", std::ios::binary | std::ios::out);
		
		// Write data to appropriate file
		// Write the level ID
		outputFile.write(reinterpret_cast<const char*>(levelID), sizeof(int));
		
		// Write the scene ID
		outputFile.write(reinterpret_cast<const char*>(sceneID), sizeof(int));
		
		// Write each inventory item (as an integer representation) to the file
		for(auto iter = inventory.begin(); iter != inventory.end(); ++iter)
		{
			outputFile.write(reinterpret_cast<const char*>(*iter), sizeof(int));
		}
		
		// close file
		outputFile.close();
		
		// unlock
		fileLock.unlock();
	}
		
}
