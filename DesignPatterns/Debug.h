#pragma once


enum DebugMode
{
	BinaryTreeStructure,
	CommandPattern,
	StateMachine,
	LatentSort,
	STL
};



class Debug {


public:
	Debug(DebugMode X)
	{
		if (X)
		{
			SetDebugState(X);
		}
	}

	void SetDebugState(DebugMode X)
	{
		CurrentDebugMode = X;
	}

	DebugMode GetDebugMode()
	{
		return CurrentDebugMode;
	}

private:
	DebugMode CurrentDebugMode;
};