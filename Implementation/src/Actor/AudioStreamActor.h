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
        virtual ~AudioStreamActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).        

        ///
        /// \brief <Give description of what happens each frame to this actor>
        virtual const ActorEvent step( Player& player ) override;

        // Declare additional functions here as specified in UML diagram.

        std::string getPath();

        void setActivated( const bool activated );

    private:
      std::string path;
      bool activated;
    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

