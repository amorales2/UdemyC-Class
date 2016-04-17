///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <string>

template<class T>
void print(T n)
{
	std::cout << "Template version: " << n << std::endl;
}

void print(int value)
{
	std::cout << "Non-Template version: " << value << std::endl;
}

template<class T>
void show()
{
	std::cout << T() << std::endl;
}

int main()
{
	//explicitly define the Type
	print<std::string>("Stuff");

	//implicit
	print("Things");
	std::cout << std::endl;

	//the implicit type definitions will favor the more direct version aka
	//the function that takes in the int in this case.
	print(5);
	print<>(6);
	print<int>(7);

	//show can only be run if you explicity define the argument type
	//show(); this will be a compiler error
	//show<>(); this will also be a compiler error
	//The compiler does not know what type you want from either of these cases
	show<double>();

	return 0;
}