#pragma once
#include <memory>
#include <iostream>




class SimpleClass 
{
public:
	SimpleClass() { std::cout << "Object Created" << std::endl; }
	~SimpleClass() { std::cout << "Object Deleted" << std::endl; }

};






class SmartPointers 
{
public:

	std::unique_ptr<SimpleClass> CreateSmartPointer()
	{
		
		std::unique_ptr<SimpleClass> Object = std::make_unique<SimpleClass>();
		return Object;
		
	}

	std::shared_ptr<SimpleClass> CreateSmartPointerShared()
	{
		std::shared_ptr<SimpleClass> SharedObject = std::make_shared<SimpleClass>();
		return SharedObject;
	}

};