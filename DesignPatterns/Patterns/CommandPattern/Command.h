#pragma once
#include <iostream>



class Command {
public:
	virtual ~Command() {
	}
	virtual void Execute() const = 0;
};


/**
 * Some commands can implement simple operations on their own.
 */
class SimpleCommand : public Command {
private:
	std::string pay_load_;

public:
	explicit SimpleCommand(std::string pay_load) : pay_load_(pay_load) {
	}
	void Execute() const override {
		std::cout << &this->pay_load_ << std::endl;
	}
};

/**
     A reciever is any class that performs operations on recieving a command
 */
class Receiver {
public:
	void DoSomething(const std::string &a) {
		std::cout << "Receiver: Working on (" << &a << ".)\n";
	}
	void DoSomethingElse(const std::string &b) {
		std::cout << "Receiver: Also working on (" << &b << ".)\n";
	}
};



/**
   Commands can be simple or very complex
 */
class ComplexCommand : public Command {
	/**
	 * @var Receiver
	 */
private:
	Receiver* receiver_;
	/**
	 * Context data, required for launching the receiver's methods.
	 */
	std::string a_;
	std::string b_;
	/**
	Commands can recieve multiple reciever objects via the constructor

	 */
public: 

	//method name : param fill, param fill, param fill
	//Initialising member variables before the body of the constructor executes.
	//this is an initalisation list.


	ComplexCommand(Receiver *receiver, std::string a, std::string b) : receiver_(receiver), a_(a), b_(b) 
	{

	}


	/**
	 * Commands can delegate to any methods of a receiver.
	 */
	void Execute() const override {
		std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
		this->receiver_->DoSomething(this->a_);
		this->receiver_->DoSomethingElse(this->b_);
	}
};

/**

 the invoker can be used for one or many commands
 it sends a request to the command

 */
class Invoker {
	/**
	 * @var Command
	 */
private:
	Command *on_start_;
	/**
	 * @var Command
	 */
	Command *on_finish_;
	/**
	 * Initialize commands.
	 */
public:
	~Invoker() {
		delete on_start_;
		delete on_finish_;
	}

	void SetOnStart(Command *command) {
		this->on_start_ = command;
	}
	void SetOnFinish(Command *command) {
		this->on_finish_ = command;
	}
	/**
	 * The Invoker does not depend on the command or receiver classes. The
	 * Invoker passes a request to a receiver indirectly, by executing a command.
	 */
	void DoSomethingImportant() {
		std::cout << "Invoker: Does anybody want something done before I begin?\n";
		if (this->on_start_) {
			this->on_start_->Execute();
		}
		std::cout << "Invoker: ...doing something really important...\n";
		std::cout << "Invoker: Does anybody want something done after I finish?\n";
		if (this->on_finish_) {
			this->on_finish_->Execute();
		}
	}
};
/**
 * The client code can parameterize an invoker with any commands.
 */
