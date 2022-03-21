#include "Fan.h"
#include <iostream>
#include "FanStatesManager.h"

Fan::Fan()
{
	// All lights are initially turned off
	currentState = &FanOff::getInstance();
}

void Fan::setState(FanState& newState)
{
	currentState->exit(this);  // do stuff before we change state
	currentState = &newState;  // actually change states now
	currentState->enter(this); // do stuff after we change state
}

void Fan::toggle()
{
	// Delegate the task of determining the next state to the current state
	currentState->toggle(this);
}