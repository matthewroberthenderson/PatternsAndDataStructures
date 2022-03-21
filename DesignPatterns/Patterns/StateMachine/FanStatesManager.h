#pragma once

#include "FanState.h"
#include "Fan.h"

class FanOff : public FanState
{
public:
	void enter(Fan* Fan) {}
	void toggle(Fan* Fan);
	void exit(Fan* Fan) {}
	static FanState& getInstance();

private:
	FanOff() {}
	FanOff(const FanOff& other);
	FanOff& operator=(const FanOff& other);
};

class FanOn : public FanState
{
public:
	void enter(Fan* Fan) {}
	void toggle(Fan* Fan);
	void exit(Fan* Fan) {}
	static FanState& getInstance();

private:
	FanOn() {}
	FanOn(const FanOn& other);
	FanOn& operator=(const FanOn& other);
};
