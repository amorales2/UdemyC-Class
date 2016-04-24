///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <utility>
class Test
{

};

//perfect forwarding allows us to call this function with either an lvalue or an
//rvalue. We can then call the correct function from there.
template<typename T>
void call(T &&arg)
{
	//Passing in an lvalue means the inferred type will be a T&. 
	//we end up with an lvalue due to the reference collapsing.

	check(std::forward<T>(arg));
	
}

void check(Test &test)
{
	std::cout << "lvalue" << std::endl;
}
void check(Test &&test)
{
	std::cout << "rvalue" << std::endl;
}



int main()
{
	//TODO: reference collapsing rules in C++11
	Test test;

	call(Test());



	return 0;
}