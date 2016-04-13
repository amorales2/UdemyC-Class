///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <exception>

void goesWrong()
{
	bool error1 = true;
	bool error2 = false;
	if (error1)
	{
		throw std::bad_alloc();
	}
	if (error2)
	{
		throw std::exception();
	}
}

int main()
{
	try
	{
		goesWrong();
	}
	/*here we MUST catch the subclass exceptions before attempting to catch
	a general exception reference. If we try to catch exception first, then
	we will catch everything as an exception reference due to polymorphism.
	This will cause undesirable behavior and it might be difficult to debug
	*/
	catch (std::bad_alloc &e)
	{
		std::cout << "Catching bad_alloc: " << e.what();
	}
	catch (std::exception &e)
	{
		std::cout<<"Catching exception: " << e.what();
	}
	
	return 0;
}