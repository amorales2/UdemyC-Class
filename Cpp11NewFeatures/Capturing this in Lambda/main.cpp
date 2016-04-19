///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>


class Test
{
private:
	int one{ 1 };
	int two{ 2 };

public:
	void run()
	{
		int three{ 3 };
		int four{ 4 };

		//we cannot capture one and two directly
		//however we can capture a reference to this
		auto pLambda = [this,three,four]() 
		{
			one = 111;
			std::cout << one << std::endl;
			std::cout << two << std::endl;
			std::cout << three << std::endl;
			std::cout << four << std::endl;
		};

		pLambda();
	}

	auto getOne() { return one; }
};



int main()
{
	Test test;
	test.run();

	//to emphasize that this is caputured by reference
	std::cout << test.getOne() << std::endl;

	return 0;
}