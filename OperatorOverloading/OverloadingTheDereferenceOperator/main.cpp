///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include "Complex.h"

int main()
{
	Complex c1(2, 4);
	//the * operator is overloaded to return the inverse of the imagionary number
	std::cout << (*c1) + *Complex(4,3) << std::endl;

	return 0;
}