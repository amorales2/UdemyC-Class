///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <string>

template<class T>
void print(T n)
{
	std::cout << n << std::endl;
}

int main()
{
	print(5);

	//explicitly define the Type
	print<std::string>("Stuff");

	//implicit
	print("Things");

	return 0;
}