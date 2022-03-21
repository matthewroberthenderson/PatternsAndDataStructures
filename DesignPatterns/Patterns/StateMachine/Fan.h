#pragma once
#include "FanState.h"

// Forward declaration to resolve circular dependency/include
class FanState;

class Fan
{
public:
	Fan();
	inline FanState* getCurrentState() const { return currentState; }
	
	void toggle();
	// This is where the magic happens
	void setState(FanState& newState);

private:
	FanState* currentState;
	
};