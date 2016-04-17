///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

//Template classes allow you to specify the type you want to work with
//This is how the std::vector class works.
#include <iostream>
#include <string>

template <class T>
class Test
{
private:
	T obj;

public:
	Test(T obj)
	{
		this->obj = obj;
	}

	void print()
	{
		std::cout << obj << std::endl;
	}
};


int main()
{
	Test<std::string> test1("Hello");
	test1.print();

	Test<int> test2(27);
	test2.print();

	return 0;
}