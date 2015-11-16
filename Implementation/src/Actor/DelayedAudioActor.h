// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedAudioActor.h
/// \brief Declares DelayedAudioActor class.
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
    /// \class DelayedAudioActor
    /// \brief :Will increment a counter every time the step method is called.
    ///        After a speciﬁed number of steps have occurred, this actor will change its TextureID
    ///        to a valid value and will be displayed. When the number of steps is equal
    ///        to the disappearing step, the TextureID will be set to an ignored value,
    ///        causing the actor to disappear.
    class DelayedAudioActor : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit DelayedAudioActor( int audioID, int delaySteps);

        // Destructor.
        virtual ~DelayedAudioActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

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

        int audioId;
        int delaySteps;
        int currentStep;
    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

