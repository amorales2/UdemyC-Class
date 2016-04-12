///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <string>

void mightGoWrong()
{
	bool error1 = false;
	bool error2 = true;

	if (error1)
	{
		throw "something went wrong";
	}
	if (error2)
	{
		throw std::string("Something else went wrong");
	}
}

void usesMightGoWrong()
{
	mightGoWrong();
}

int main()
{
	try
	{
		usesMightGoWrong();
	}
	catch (int e)
	{
		switch (e)
		{
		case 8:
			std::cout << "Error code: " << e << std::endl;
		default:
			break;
		}
	}
	catch (char const* e)
	{
		std::cout << "Error Message: " << e << std::endl;
	}
	catch (std::string e)
	{
		std::cout << "Error Message: " << e << std::endl;
	}

	std::cout << "Still working!";

	return 0;
}