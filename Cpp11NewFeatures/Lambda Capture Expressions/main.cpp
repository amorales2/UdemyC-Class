///////////////////////////////////////////////////////////////////////////////
//main.cpp
//
#include <iostream>

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;
	int sum;

	//in order to use local variables, we must "capture" them using the square
	//brackets at the front of the lambda expression. 
	//pass-by-value
	[one,two]() 
	{
		std::cout << one <<","<< two << std::endl;
	}();

	//This will capture all local variables by value
	[=]()
	{
		std::cout << one << "," << two << "," <<three<< std::endl;
	}();

	//This will capture all local variables by value EXCEPT for sum
	[=, &sum]()
	{
		sum = one + two + three;
	}();

	//sum is now 6. We changed its value in the lambda expression because
	//we passed it by reference
	std::cout << sum << std::endl;

	//this will capture all by reference, but one by value
	[&, one]()
	{
		std::cout << one << "," << two << "," << three << std::endl;
	}();



	return 0;
}