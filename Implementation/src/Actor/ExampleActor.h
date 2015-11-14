// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file ExampleActor.h
/// \brief Declares ExampleActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace USA {

    // Create new Actor and derive from BaseActor.
    // Provide documentation, do so by starting with "///"
    ///
    /// \class ExampleActor
    /// \brief <Give brief description here>
    class ExampleActor : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit ExampleActor( void );

        // Destructor.
        virtual ~ExampleActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

        // Override onClick, onHover, and step, provide documentation.

        ///
        /// \brief <Give description of what actor does on click>
        virtual const ActorEvent onClick( Player& player ) override;

        ///
        /// \brief <Give description of what actor does on hover>
        virtual const ActorEvent onHover( Player& player ) override;

        ///
        /// \brief <Give description of what happens each frame to this actor>
        virtual const ActorEvent step( Player& player ) override;

        // Declare additional functions here as specified in UML diagram.

    private:

        // Declare any data members here as specified in UML diagram.

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
