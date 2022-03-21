#pragma once
#include <iostream>



class LinkListNode {
public:
	//values, stuff to store
	int data;

	//the link pointer to the next LinkListNode 
	LinkListNode * next;




};



class LinkListFunctions {

public:
	LinkListFunctions() {};

	void printList(LinkListNode* n)
	{
		while (n != NULL) {
			std::cout << n->data << " ";
			n = n->next;
		}
	}

	void clearList(LinkListNode* n)
	{
		delete n;
	}

	

};