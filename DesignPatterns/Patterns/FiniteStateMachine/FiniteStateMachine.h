#pragma once
#include <iostream>
#include <chrono>


enum Gripped
{
	GrippedNone,
	GrippedOnce,
	GrippedTwice,
	GrippedThreeTimes,
	GrippedFourTimes

};


class GripStateHandler
{
	

public:
	
	Gripped currentState = Gripped::GrippedNone;
	float LastStateChange;
	int GrippingState = 0;
	void SetCurrentState(Gripped state) {
		currentState = state;
		LastStateChange = clock();

	}



	float getStateElapsed() {
		return clock() - LastStateChange;
	}


	void SMachine()
	{

		switch (currentState)
		{
		case Gripped::GrippedNone:
			//first time gripped
			if (GrippingState > 0) 
			{
				
				SetCurrentState(Gripped::GrippedOnce);
			}
			
			//if (getStateElapsed() > 5.0) {
			//	SetCurrentState(Gripped::GrippedOnce);
		//	}

			break;
		case Gripped::GrippedOnce:
			//first time gripped falloff
			if (GrippingState == 0)
			{
				
				SetCurrentState(Gripped::GrippedTwice);
			}
			break;

		case Gripped::GrippedTwice:
			//first time released Trigger
			if (GrippingState > 0)
			{
				SetCurrentState(Gripped::GrippedThreeTimes);
			}

		case Gripped::GrippedThreeTimes:
			//first time released Trigger falloff
			if (GrippingState == 0)
			{
				SetCurrentState(Gripped::GrippedNone);
			}

			return;
		}


	}






};