///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
	int value{ 5 };
	std::cout << value << std::endl;

	std::string text{ "Hello" };
	std::cout << text << std::endl;

	int numbers[]{ 1,3,4 };
	std::cout << numbers[1] << std::endl;

	int *pInts = new int[3]{ 1,2,3 };
	std::cout << pInts[1] << std::endl;
	delete pInts;

	int value1{};
	std::cout << value1 << std::endl;

	int *pSomething{ &value };
	std::cout << *pSomething << std::endl;

	int *pSomething1{}; //equivalent to int *pSomething = nullptr
	std::cout << pSomething1 << std::endl;
	
	int numbers1[5]{};//initializes values to 0
	std::cout << numbers1[1] << std::endl;

	//struct example --------------------------
	struct 
	{
		int value;
		std::string text;
	} s1{ 5,"Hi" }; //notice the lack of an = sign
	std::cout << s1.text<<": "<<s1.value << std::endl;

	//vector example --------------------------
	std::vector<std::string> strings{ "one","two","three" };
	std::cout << strings[2] << std::endl;


	return 0;
}