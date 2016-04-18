///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


#include <iostream>
#include <string>

//auto can be useful for dynamic template functions
template<class T,class S>
auto test(T value1, S value2) -> decltype(value1 + value2)
{
	return value1+value2;
}

int get()
{
	return 999;
}

auto test2() -> decltype(get())
{
	return get();
}

int main()
{
	//this works for primitative types but you might as well just
	//give the type you want to avoid the (small) overhead of auto.
	auto value = 7;
	
	//c-style string (char* array)
	auto text = "Hello";

	std::cout << test(5,6) << std::endl;
	std::cout << test2() << std::endl;
	return 0;
}