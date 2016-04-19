///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <string>
#include "ring.h"
int main()
{
	ring<std::string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");
	textring.add("four");
	textring.add("five");

	//C++98 style
	for (ring<std::string>::iterator it = textring.begin(); it != textring.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	//C++11 style
	//because we successfully implemented the above version, this shorthand
	//for loop will work with our custom class.
	for (auto value : textring)
	{
		std::cout << value << std::endl;
	}
	
	return 0;
}