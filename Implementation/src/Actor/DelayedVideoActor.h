// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedVideoActor.h
/// \brief Declares DelayedVideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once // Includes this file only once in compilation; speeds up building.

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We will need to know about BaseActor.
#include "BaseActor.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// We define our stuff inside a namespace.
namespace teamusa{

	 // Create new Actor and derive from BaseActor.
	 // Provide documentation, do so by starting with "///"
	 ///
	 /// \class DelayedVideoActor.h
	 /// \brief Will increment a counter every time the step method is called.
	 ///After a specified number of steps have occurred,
  	 ///this actor will change its TextureID to a valid value and will be displayed.
	 ///When the number of steps is equal to the disappearing step,
	 ///the TextureID will be set to an ignored value, causing the actor to disappear
class DelayedVideoActor : public BaseActor
{
private:
	int textureId;
	int delaySteps;
	int currentStep;
	int disappear;

public:
	// Declare constructor and destructor...

	// Constructor.
	explicit DelayedVideoActor( Region region, int textureID, int delaysteps, int disappearStep,int layer );

	// Destructor.
	virtual ~DelayedVideoActor( void ) override; // Use "override" keyword to remind yourself/others that this is overriding a parent class method (not necessary).

	// Override onClick, onHover, and step, provide documentation.

	///
	/// \brief <Give description of what actor does on click>
	virtual const ActorEvent onClick( Player& player ) override;

	///
	/// \brief <Give description of what actor does on hover>
	virtual const ActorEvent onHover( Player& player ) override;

	///
	/// \brief increment a step counter
	virtual const ActorEvent step( Player& player ) override;
};
};
