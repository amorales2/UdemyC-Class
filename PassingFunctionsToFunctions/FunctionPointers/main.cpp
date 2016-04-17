///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>

void test(int value)
{
	std::cout << "Hello: " << value << std::endl;
}


int main()
{
	test(2);

	//void function pointer that points to a function taking no parameters
	void(*pTest)(int);
	pTest = test;

	pTest(20);


	return 0;

}