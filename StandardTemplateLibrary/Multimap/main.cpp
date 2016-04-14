///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <map>
#include <string>

//multimaps let you store multiple values associated with a specific key
int main()
{
	std::multimap<int, std::string> lookup;

	lookup.insert(std::make_pair(30, "Mike"));
	lookup.insert(std::make_pair(10, "Vickey"));
	lookup.insert(std::make_pair(30, "Raj"));
	lookup.insert(std::make_pair(20, "Bob"));

	for (auto it = lookup.begin();it != lookup.end();++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << std::endl;

	//iterate through the multimap starting from the first element where the key is 20
	for (auto it = lookup.find(20);it != lookup.end();++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << std::endl;

	//this is a method of iterating through a particular key range in a multimap.
	//equal_range() will return a pair of iterators (begin and end) to the particular
	//range we specify

	//for C++11 and beyond, we can use the auto keyword to massivly simplify variable
	//declarations such as this. Without auto, the variable its would look like this:
	//std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> its = lookup.equal_range(30);
	auto its = lookup.equal_range(30);
	for (auto it = its.first;it != its.second;++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}

	return 0;
}