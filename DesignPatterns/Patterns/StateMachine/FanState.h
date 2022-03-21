#pragma once
#include <iostream>
#include "Fan.h"

// Forward declaration to resolve circular dependency/include
class Fan;

class FanState
{
public:
	virtual void enter(Fan* Fan) = 0;
	virtual void toggle(Fan* Fan) = 0;
	virtual void exit(Fan* Fan) = 0;
	virtual ~FanState() {}



};

