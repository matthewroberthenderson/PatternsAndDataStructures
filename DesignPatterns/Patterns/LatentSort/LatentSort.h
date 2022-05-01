#pragma once

#include <thread>




class ThreaderMain {

public:
	

	void FPoint()
	{

	};

	void FunctionPointer()
	{
		std::cout << "still Working" << std::endl;
	}

	float * Time;

	void Function(float &Time) 
	{

		std::thread([] 
		{
			float Time = 0;
			while (true) 
			{
				Time+=1.0;
			}
			

		}).detach();

		
	}


};



struct AbsLock
{
	void(ThreaderMain:: *A)() = &ThreaderMain::FunctionPointer;
	int s = 0;
};

class AbstractionMain
{

public:
	AbsLock BaseEL;
	void(ThreaderMain:: *E)() = BaseEL.A;

};