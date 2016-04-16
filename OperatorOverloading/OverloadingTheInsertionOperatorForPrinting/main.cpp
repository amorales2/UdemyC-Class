///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <string>

class Test
{
private:
	int id;
	std::string name;

public:
	Test() :id(0), name("")
	{

	}

	Test(int id, std::string name) :id(id), name(name)
	{

	}

	//copy constructor
	Test(const Test &other)
	{
		*this = other;
	}

	void print()
	{
		std::cout << id << ": " << name << std::endl;
	}

	const Test &operator =(const Test &other)
	{
		id = other.id;
		name = other.name;

		return *this;
	}
	//friend is required because we are accessing private member data from outside
	//its scope. Calling this "friend" will allow it to access private variables.
	//to avoide having to do this, you could use getter and setter functions for
	//accessing private member data.
	friend std::ostream &operator <<(std::ostream &out, const Test &test)
	{
		out << test.id << ": "<<test.name;
		return out;
	}
};

int main()
{
	Test test1(10, "Mike");
	Test test2(20, "Bob");

	//in order to do this, the '<<' operator must be overloaded in the Test class
	//the bitshift operator has left-right associativity 
	std::cout << test1 << test2<< std::endl;

	return 0;
}