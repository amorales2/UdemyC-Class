///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <ostream>
#include <vector>

class Test
{
public:
	Test()
	{
		std::cout << "Constructor" << std::endl;
	}

	Test(int i)
	{
		std::cout << "Parameterized constructor" << std::endl;
	}

	Test(const Test &other)
	{
		std::cout << "copy constructor" << std::endl;
	}

	Test &operator = (const Test &other)
	{
		std::cout << "assignment" << std::endl;
		return *this;
	}

	~Test()
	{
		std::cout << "destructor" << std::endl;
	}

	friend std::ostream &operator << (std::ostream &out, const Test &test);
};

std::ostream &operator <<(std::ostream &out, const Test &test)
{
	out << "Hello from test";
	return out;
}

Test getTest()
{
	return Test();
}

int main()
{
	//c++11 has return value optimization for situations like this.
	//in C++98, you end up constructing, copying, and destructing multiple
	//objects in order to create, pass, and assign the single object you want.
	
	//in order to see this happening, a flag is needed in the compiler to disable
	//certain compiler optimizations. In a real-world application, just be aware
	//that the compiler should be doing these optimizations but there might be
	//situations where it fails to do so, leaving you with poor performance.
	Test test1 = getTest();
	std::cout << test1 << std::endl;

	std::vector<Test> vec;
	vec.push_back(Test());


	return 0;
}