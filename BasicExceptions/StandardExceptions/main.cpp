///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

//this does not work as it does in the lecture. Creating an array that is too
//large will generate a compiler error in Visual Studio. It might not be that
//way in Eclipse using the gcc compiler.

#include <iostream>
class CanGoWrong
{
public:
	CanGoWrong()
	{
		char *pMemory = new char[9999999];
		delete[] pMemory;
	}
};
int main()
{
	try 
	{
		CanGoWrong wrong;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}