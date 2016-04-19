///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <string>
class Test
{
	int id{ 3 };
	std::string name{"Mike"};
public:
	//clear way to define a default constructor
	Test() = default;
	
	//works for the copy constructor as well
	Test(const Test &other) = default;

	//also works for the default '=' overload
	//however, we can also delete the default constructors, as well as the 
	//assignment overload as I am doing below
	Test &operator =(const Test &other) = delete;

	Test(int id) :
		id(id)
	{

	}

	void print()
	{
		std::cout << id << ": " << name << std::endl;
	}
};


int main()
{
	Test test;
	test.print();

	Test test1(77);
	test1.print();

	Test test2 = test1; //copy constructor

	//this will not work because we deleted the assignment overload
	//test2 = test; //assignment operator overload
	return 0;
}