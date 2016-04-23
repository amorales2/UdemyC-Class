///////////////////////////////////////////////////////////////////////////////
//main.cpp
//
#include <iostream>


class Parent
{
public:
	void speak()
	{
		std::cout << "Parent Speaking!" << std::endl;
	}
};

class Brother : public Parent
{

};

class Sister : public Parent
{

};


//static_casts are compile-time casts. This can introduce bugs into your code
//because there is no runtime checking. If you cast a superclass object into 
//a baseclass pointer for example, you could try to call functions on it
//accidently which will cause the program to crash or not work properly.
int main()
{
	Parent parent;
	Brother brother;

	float value = 3.23;
	//c-style cast
	std::cout << (int)value << std::endl;
	
	std::cout << int(value) << std::endl;

	//C++ static_cast
	std::cout << static_cast<int>(value) << std::endl;

	//polymorphism: storing a subclass object in a superclass variable
	Parent *pp = &brother;

	//this works but its very unsafe
	Brother *pb = static_cast<Brother *>(&parent);

	//this also works but it can be error prone. Static casts are compile-time
	//casts without any runtime checking.
	Brother *pbb = static_cast<Brother *>(pp);
	std::cout << pbb << std::endl;

	//passing an lvalue to an rvalue reference
	Parent &&p = static_cast<Parent &&>(parent);
	p.speak();

	return 0;
}