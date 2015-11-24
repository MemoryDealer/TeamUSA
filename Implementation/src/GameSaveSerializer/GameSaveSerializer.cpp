// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
//
// Author: Vincent Sanchez
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file GameSaveSerializer.cpp
/// \brief Implements save file serializer class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "GameSaveSerializer.h"

#include "Engine/Assert.h"

//--------

namespace teamusa {
	
	GameSaveSerializer::GameSaveSerializer(void)
    : fileLock()
    , slot( 1 )
	{
		
	}
	
	GameSaveSerializer::~GameSaveSerializer(void)
	{
		
	}

    void GameSaveSerializer::setSlot( const int32_t in_slot )
    {
        Assert( ( in_slot >= 1 ) && ( slot <= 3 ) );
        slot = in_slot;
    }
	
	bool GameSaveSerializer::load(int &levelID, int &sceneID, Player::Inventory &inventory)
	{		
		// Retrieve appropriate file
		std::ifstream inputFile;
		inputFile.open( "saves/slot" + std::to_string( slot ), std::ios::binary | std::ios::in);

        // If the file is not there, give default values.
        if ( !inputFile.is_open() ) {
            return false;
        }
		
		// Read appropriate file contents
		// Read the level ID
		inputFile.read(reinterpret_cast<char*>(&levelID), sizeof(int));
		
		// Read the scene ID
		inputFile.read(reinterpret_cast<char*>(&sceneID), sizeof(int));
		
		// Read the inventory contents
		while (!inputFile.eof())
		{
            int item = 0;
			inputFile.read(reinterpret_cast<char*>(&item), sizeof(int));
            inventory.push_back( item );
		}
		// close file
		inputFile.close();
        return true;
	}
	
	void GameSaveSerializer::save(const int &levelID, const int &sceneID, const Player::Inventory &inventory)
	{
		// Launch the new thread and intiaite save
		std::thread saveThread(&GameSaveSerializer::saveInThread, this, levelID, sceneID, inventory);
		saveThread.detach();
	}
	
	void GameSaveSerializer::saveInThread(const int levelID, const int sceneID, const Player::Inventory inventory)
	{
		// Lock the thread
		fileLock.lock();
		
		//Open the approriate data stream
		std::ofstream outputFile;
		outputFile.open("saves/slot" + std::to_string( slot ), std::ios::binary | std::ios::out);
		
		// Write data to appropriate file
		// Write the level ID
		outputFile.write(reinterpret_cast<const char*>(&levelID), sizeof(int));
		
		// Write the scene ID
		outputFile.write(reinterpret_cast<const char*>(&sceneID), sizeof(int));
		
		// Write each inventory item (as an integer representation) to the file
		for(auto iter = inventory.begin(); iter != inventory.end(); ++iter)
		{
            const int32_t item = *iter;
			outputFile.write(reinterpret_cast<const char*>(&item), sizeof(int));
		}
		
		// close file
		outputFile.close();
		
		// unlock
		fileLock.unlock();
	}
		
}
