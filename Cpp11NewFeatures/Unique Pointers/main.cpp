///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <memory>//required for smart pointers

class Test
{
public:
	Test()
	{
		std::cout << "created" << std::endl;
	}
	void greet()
	{
		std::cout << "Hello" << std::endl;
	}
	~Test()
	{
		std::cout << "destroyed" << std::endl;
	}
};

class Temp
{
private:
	std::unique_ptr<Test[]> pTest;

public:
	Temp() 
		:pTest(new Test[2])
	{

	}
};

int main()
{
	//smart pointers handle the deallocation of memory for you.
	//for unique_ptr, the memory is cleaned up when we leave the scope the 
	//variable lived in.
	{
		std::unique_ptr<Test> pTest(new Test);

		pTest->greet();
	}

	{
		std::unique_ptr<Test[]> pTest(new Test[2]);

		pTest[1].greet();
	}

	//when this variable goes out of scope here, the unique_ptr will automatically
	//clean up the memory in the object without having to delete the data in a 
	//destructor.
	{
		Temp temp;
	}


	std::cout << "Finished" << std::endl;

	return 0;
}