///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>

void test(void(*pFunc)() )
{
	pFunc();
}

int main()
{

	//lambda expressions are anonymous functions aka function with no name
	//Here we are storing the function by reference in the variable func.
	auto func = []() {std::cout << "Hello" << std::endl;};
	func();

	//the function can be called by addeding the round brackets to the end
	[]() {std::cout << "Hello again" << std::endl;}();


	//we can send the lambda as an argument
	test(func);

	//we can send the lambda directly in the function call
	test([]() {std::cout << "Hello again again" << std::endl;});

	return 0;
}