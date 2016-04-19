///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

class Test
{
public:
	Test(std::initializer_list<std::string> texts)
	{
		for (auto value : texts)
		{
			std::cout << value << std::endl;
		}
	}

	//this can be done with functions as well
	void print(std::initializer_list<std::string> texts)
	{
		for (auto value : texts)
		{
			std::cout << value << std::endl;
		}
	}

};


int main()
{
	std::vector<int> numbers{ 1,2,3,4 };
	std::cout << numbers[2] << std::endl;

	Test test{ "apple","orange","banana" };
	test.print({ "one","two","three","four" });

	return 0;
}