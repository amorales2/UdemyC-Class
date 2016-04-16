///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include "Complex.h"

int main()
{
	Complex c1(3, 2);
	Complex c2(3, 2);

	if (c1 == c2)
	{
		std::cout << "Equal" << std::endl;
	}
	else
	{
		std::cout << "Not Equal" << std::endl;
	}

	if (c1 != c2)
	{
		std::cout << "Not equal" << std::endl;
	}
	else
	{
		std::cout << "Equal" << std::endl;
	}

	return 0;
}