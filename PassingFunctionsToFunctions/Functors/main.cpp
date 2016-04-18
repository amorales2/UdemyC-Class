///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <string>

struct Test
{
	virtual bool operator() (std::string &text) = 0;
	virtual ~Test(){}
};


//variables are public by default in a struct
struct MatchTest : public Test
{
	virtual bool operator() (std::string &text) override 
	{
		return text == "lion";
	}
};

void check(std::string text, Test& test)
{
	if (test(text))
	{
		std::cout << "Text Matches!" << std::endl;
	}
	else
	{
		std::cout << "No Match." << std::endl;
	}
}

int main()
{

	MatchTest pred;

	//pred() is NOT a function call. We have overloaded the () operator to return
	//true or false (1 or 2) depending on if the rhs value is equal to "lion"
	std::string value = "lion";
	std::cout << pred(value) << std::endl;

	std::cout << std::endl;

	MatchTest m;
	check("lion",m);
	return 0;
}