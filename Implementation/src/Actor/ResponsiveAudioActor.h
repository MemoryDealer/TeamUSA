// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
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
namespace teamusa {

    // Create new Actor and derive from BaseActor.
    // Provide documentation, do so by starting with "///"
    ///
    /// \class ResponsiveAudioActor
    /// \brief Will increment the value of stepCount until it is equal to durationSteps
    ///         for each call to the step method. A call to onClick or onHover will set the
    ///         value of stepCount to zero and emit an AudioID and value if stepCount is equal
    ///         to durationSteps. The hoverAudioID or clickAudioID can be set to an invalid AudioID
    ///         value to prevent sound from being played.
    class ResponsiveAudioActor : public BaseActor
    {

    public:

        // Declare constructor and destructor...

        // Constructor.
        explicit ResponsiveAudioActor( Region region, int hoverAudioId, int clickAudioId);

        // Destructor.
        virtual ~ResponsiveAudioActor( void ) override; 

		///
		/// \brief Generates an ActorEvent when the actor's region is clicked. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action. 
        virtual const ActorEvent onClick( Player& player ) override;

        ///
        /// \brief Generates an ActorEvent when the actor's region is hovered over. 
		/// \param Player The player.
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent onHover( Player& player ) override;

		///
		/// \brief Advances the actor one frame. 
		/// \param Player The player
		/// \return Returns an ActorEvent that triggers an actor to perform an action.
        virtual const ActorEvent step( Player& player ) override;

        // Declare additional functions here as specified in UML diagram.

    private:
        int hoverAudioId;
        int clickAudioId;
    };

}


