///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include "Complex.h"

int main()
{
	Complex c1(2, 3);

	//copy constructor
	Complex c2(c1);

	Complex c3 = c2;

	std::cout << c2 << ": " << c3 << std::endl;
	return 0;
}