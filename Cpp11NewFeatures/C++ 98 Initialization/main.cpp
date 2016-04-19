///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <string>
#include <vector>
int main()
{
	//array example -----------------------
	int value[] = { 1,4,5 };
	std::cout << value[0] << std::endl;

	//class example -----------------------
	class C
	{
	public:
		std::string text;
		int id;
	};

	C c1 = { "Hello",7 };
	std::cout << c1.text << std::endl;


	//struct example ----------------------
	struct S
	{
		std::string text;
		int id;
	};
	S s1 = { "Hello", 7 };
	std::cout << s1.text << std::endl;

	//another struct example --------------
	struct R
	{
		std::string text;
		int id;
	} r1 = { "Hello", 7 },r2;
	r2 = { "Goodbye", 34 };
	std::cout << r1.text << std::endl;
	std::cout << r2.text << std::endl;
	
	//vector example ----------------------
	//in order to use the braces to initialize vector values,
	//we have to use C++11
	std::vector<std::string> strings;

	strings.push_back("One");
	strings.push_back("Two");
	strings.push_back("Three");

	return 0;
}