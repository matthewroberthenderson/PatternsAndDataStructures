#include <iostream>
#include <thread>
#include "DataStructures/LinkList.h"
#include "Patterns/CommandPattern/Command.h"
#include "Patterns/StateMachine/Fan.h"




void main() {






	//Command Pattern --------------------------------------------------------------------------------------------------------------

	Invoker *invoker = new Invoker;
	invoker->SetOnStart(new SimpleCommand("Say Hi!"));
	Receiver *receiver = new Receiver;
	invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
	invoker->DoSomethingImportant();

	//remove from heap
	delete invoker;
	delete receiver;








	//link list-----------------------------------------------------------------------------------------------------------------
	LinkListNode * head = NULL;
	LinkListNode * second = NULL;
	LinkListNode * third = NULL;


	//heap values.
	head = new LinkListNode();
	second = new LinkListNode();
	third = new LinkListNode();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;


	// Good example why you need to be careful about when and how you manage memory
	//delete this memory from the heap causing a read access violation when accessing the pointer in printlist method.
	// delete head;
	// try it out if you dare

	LinkListFunctions * linkers = new LinkListFunctions;
	linkers->printList(head);
	






	//state machine------------------------------------------------------------------------------------------------------------------------------------------
	Fan * fanInstance = new Fan;

	//my addition to this just to show a basic example of the StateMachine
	std::thread([&] {
		int Timer = 0;
		
		while (true)
		{
			if (Timer <= 100) 
			{
				Timer += 1;
				//std::cout << Timer << std::endl;
				//std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
			else {

				fanInstance->toggle();
				Timer = 0;
			}
		}

	}).detach();


	std::cin.get();

	

	
}