///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <vector>
int main()
{
	auto texts = { "one","two","Three" };

	//shorthand forloop.
	//text will take the value of each element in the texts array
	for (auto text : texts)
	{
		std::cout << text << std::endl;
	}
	std::cout << std::endl;

	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(3);
	numbers.push_back(11);
	numbers.push_back(22);
	numbers.push_back(7);
	//loop through all the elements in a vector without using a vector iterator
	for (auto number : numbers)
	{
		std::cout << number << std::endl;
	}
	std::cout << std::endl;

	//loop through all the elements of an std::string
	std::string hello = "Hello";
	for (auto c : hello)
	{
		std::cout << c << std::endl;
	}
	std::cout << std::endl;



	return 0;
}