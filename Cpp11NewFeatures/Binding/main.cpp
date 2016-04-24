///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <functional>

using namespace std::placeholders;

class Test 
{
public:
	int addFromClass(int a, int b, int c)
	{
		std::cout << a << ", " << b << ", " << c << std::endl;
		return a + b + c;
	}
};


int add(int a, int b, int c)
{
	std::cout << a << ", " << b << ", " << c << std::endl;
	return a + b + c;
}


int run(std::function<int(int, int)> func)
{
	return func(7, 3);
}
//binding is new to C++11. Previously found in the boost libraries
int main()
{
	//function pointer and arguments for that function
	//we are now able to call this function with the given arguments multiple
	//times very easily.
	auto calculate = std::bind(add, 3, 4, 5);
	std::cout << calculate() << std::endl;

	//here we are using std::placeholders. By using these, we will still have to
	//provide the variables when calling the function. This can simplify function
	//calls that take a lot of parameters.
	auto calculate1 = std::bind(add, _1, _2, _3);
	std::cout << calculate1(3, 4, 5) << std::endl;

	//using std::placeholders out of order means they will be sent to the function
	//out of order.
	auto calculate2 = std::bind(add, _2, _3, _1);
	std::cout << calculate2(3, 4, 5) << std::endl;

	//we can send a function that is bound to a variable as a std::function 
	//argument to another function as well.
	auto calculate3 = std::bind(add, _2, 100, _1);
	std::cout << run(calculate3) << std::endl;

	//we can also bind to a class function. For this, we must send a reference to
	//the class as well as a particular object we are calling the function on.
	Test test;
	auto calculate4 = std::bind(&Test::addFromClass, test, _2, 300, _1);
	std::cout << run(calculate4) << std::endl;

	return 0;
}