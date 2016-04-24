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

int main()
{
	//shared pointers dont delete the memory of the object until all pointers
	//using that memory go out of scope. Currently cannot be used for arrays
	std::shared_ptr<Test> pTest2(nullptr);//initialize with nullptr

	//using a shared_ptr means this will not delete the memory when we leave
	//the scope. The memoery still has a shared_ptr pointing at it and it wont
	//be cleaned up until we leave the main scope.
	{
		std::shared_ptr<Test> pTest = std::make_shared<Test>();
		pTest2 = pTest;
		auto pTest3 = pTest;
	}

	std::cout << "Finished" << std::endl;

	return 0;
}