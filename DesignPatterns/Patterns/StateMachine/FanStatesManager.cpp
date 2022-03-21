#include "FanStatesManager.h"



FanState &FanOff::getInstance()
{
	static FanOff singleton;
	//std::cout << "FanOff" << std::endl;
	return singleton;
}

void FanOff::toggle(Fan* Fan)
{
	// Low -> Medium
	Fan->setState(FanOn::getInstance());
}


FanState &FanOn::getInstance()
{
	static FanOn singleton;
	//std::cout << "FanOn" << std::endl;
	return singleton;
}


void FanOn::toggle(Fan* Fan)
{
	// Low -> Medium
	Fan->setState(FanOff::getInstance());
}



