// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file AudioStreamActor.h
/// \brief Declares AudioStreamActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa {

    // Create new Actor and derive from BaseActor.
    // Provide documentation, do so by starting with "///"
    ///
    /// \class AudioStreamActor
    /// \brief If this actor is not activated, it will emit a StreamAudio event
    ///        and set its status to activated when the step method is called.
    ///        The engine can then retrieve the path to the audio file by a call to
    ///        this actor's getPath method.
    class AudioStreamActor : public BaseActor
    {

    public:
        // Declare constructor and destructor...
        // Constructor.
        explicit AudioStreamActor( std::string path);

        // Destructor.
        virtual ~AudioStreamActor( void ) override;        

        ///
        /// \brief This method updates the player on every frame.
		/// \param Player The player
		/// \return Returns an ActorEvent that triggers an action from one or more actors. 
        virtual const ActorEvent step( Player& player ) override;

        // Declare additional functions here as specified in UML diagram.
		///
		/// \brief This method gets the path to the requested audio file. 
		/// \return Returns a file path formatted as a string. 
        std::string getPath();

    private:
      std::string path;
      bool activated;
    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

