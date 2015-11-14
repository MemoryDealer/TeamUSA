v// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// Legend of the Great Unwashed (Working Title).
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file ResponsiveAudioActor.h
/// \brief Declares ResponsiveAudioActor class.
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
    /// \class ResponsiveAudioActor
    /// \ Brief: Will increment the value of stepCount until it is equal to durationSteps
    ///         for each call to the step method. A call to onClick or onHover will set the
    ///         value of stepCount to zero and emit an AudioID and value if stepCount is equal
    ///         to durationSteps. The hoverAudioID or clickAudioID can be set to an invalid AudioID
    ///         value to prevent sound from being played.
    class ResponsiveAudioActor : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit ResponsiveAudioActor( Region region, int hoverAudioId, int durationSteps, int clickAudioId);

        // Destructor.
        virtual ~ResponsiveAudioActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

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
        int hoverAudioId;
        int clickAudioId;
        int durationSteps ;
        int stepCount;
    };

}


