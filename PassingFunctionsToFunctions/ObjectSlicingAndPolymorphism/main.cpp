///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>

class Parent 
{
private:
	int one;
public:
	
	Parent() : one(0)
	{

	}

	Parent(const Parent &other) : one(0)
	{
		one = other.one;
		std::cout << "copy parent" << std::endl;
	}

	virtual void print()
	{
		std::cout << "parent" << std::endl;
	}
	virtual ~Parent()
	{

	}
};

class Child : public Parent
{
private:
	int two;

public:
	Child() : two(0)
	{

	}

	void print()
	{
		std::cout << "child" << std::endl;
	}
};


int main()
{
	Child c1;
	Parent &p1 = c1;

	//this will print "child" because we have made the parent function virtual.
	//This correctly puts the functions in a virtual table of function pointers
	//that will point to the correct function for object type, reguardless of
	//its container variable.
	p1.print();

	Parent p2 = Child();
	p2.print();


	return 0;
}
