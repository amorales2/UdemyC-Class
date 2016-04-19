///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <string>


void testGreet(void(*greet)(std::string))
{
	greet("Bob");
}

void runDivide(double(*divide)(double, double))
{
	double rval = divide(9,3);
	std::cout << rval << std::endl;
}


int main()
{
	//arguments list example ---------------------
	auto pGreet = [](std::string name) 
	{
		std::cout << "Hello " << name << std::endl;
	};

	pGreet("Mike");
	testGreet(pGreet);

	//return type example ------------------------
	auto pDivide = [](double a, double b) -> double
	{
		if (b == 0.0)
		{
			//This will not work because auto thinks 0 is an int value
			//and functions with auto return types have to have consistent
			//return types. We can use the trailing return type syntax.
			//specifing it a double will force the 0 to be returned as a
			//double
			return 0;
		}
		return a / b;
	};

	std::cout << pDivide(10.0, 5.0) << std::endl;
	std::cout << pDivide(10.0, 0) << std::endl;
	runDivide(pDivide);
	return 0;
}