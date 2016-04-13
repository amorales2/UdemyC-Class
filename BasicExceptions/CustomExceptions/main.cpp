///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <exception>

class MyException : public std::exception
{
public:

	//doing it this way with the const throw() added will cause the function to 
	//not throw any excpetions. 

	virtual const char* what() const throw () override
	{
		return "Something bad Happened";
	}

};

class Test 
{
public:
	void goesWrong()
	{
		throw MyException();
	}
};

int main()
{
	Test test;
	try
	{
		test.goesWrong();
	}
	catch (MyException &e)
	{
		std::cout<<e.what();
	}

	return 0;
}