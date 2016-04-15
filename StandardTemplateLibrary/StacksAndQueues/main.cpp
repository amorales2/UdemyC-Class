///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>

class Test 
{
private:
	std::string name;

public:

	Test(std::string name) :
		name(name)
	{

	}
	~Test()
	{
		//std::cout << "Destructor called" << std::endl;
	}
	void print()
	{
		std::cout << name << std::endl;
	}
};

//stacks are not used to iterate through. If you think you need to iterate
//through a stack, then you probably need a vector, linked list etc...
int main()
{
	//stack is LIFO structure
	std::stack<Test> testStack;

	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Sue"));

	//this will return a reference to the object in the top of the stack.
	//we are using a shadow copy to copy the data into test1. Getting a reference,
	//instead is dangerious because if the object is popped from the stack, you
	//could end up with undefined behavior.
	//example:
	/*
	Test &test1 = testStack.top();
	testStack.pop();
	test1.print();
	*/
	//this MIGHT work and it MIGHT not. 


	//These will be printed in reverse order from being pushed into the stack
	while (testStack.size() > 0)
	{
		Test test = testStack.top();
		test.print();
		testStack.pop();
	}

	std::cout << std::endl;
	//----------------------------------------------------------------------------
	//FIFO structure
	std::queue<Test> testQueue;

	testQueue.push(Test("Mike"));
	testQueue.push(Test("John"));
	testQueue.push(Test("Sue"));

	//can display items from the back as well
	testQueue.back().print();
	std::cout << std::endl;


	//display items from the front of the queue to the back
	while (testQueue.size() > 0)
	{
		Test test = testQueue.front();
		test.print();
		testQueue.pop();
	}

	return 0;
}