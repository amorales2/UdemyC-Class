///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <typeinfo>//need this otherwise typeid values are not guaranteed
#include <string>
//Decltype is a new C++11 keyword
//NOTE: in gnu gcc compiler, you must specifically enable C++11
int main()
{
	//typeid will return the type of the variable sent to it.
	//for the case of std::string, we get some name mangling displayed with it.
	//This is extra information about the type that you might need in order to
	//overload functions etc...
	std::string value;
	std::cout << typeid(value).name() << std::endl;

	//decltype allows us to set a variable to the same type as something passed
	//into it. This can be useful for creating a complex variable or setting a
	//variable to the return type of a particular function.
	decltype(value) name = "Bob";
	std::cout << name << std::endl;
	std::cout << typeid(name).name() << std::endl;


	return 0;
}