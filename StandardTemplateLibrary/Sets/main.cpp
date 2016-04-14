///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <set>
#include <string>

class Test
{
private:
	int id;
	std::string name;
public:
	//default constructor
	Test() :id(0),	name(""){}

	Test(int id, std::string name) :
		id(id),
		name(name)
	{

	}
	void print() const
	{
		std::cout << id << ": " << name << std::endl;
	}

	bool operator< (const Test &other)const
	{
		return name < other.name;
	}

};



//everything stored in a set is unique. If you attempt to add the same value
//to the set again, it is ignored.
int main()
{
	std::set<int> numbers;
	numbers.insert(50);
	numbers.insert(10);
	numbers.insert(30);
	numbers.insert(20);
	numbers.insert(20);

	for (auto it = numbers.begin();it != numbers.end();++it)
	{
		std::cout << *it << std::endl;
	}

	//check for an element in numbers using the find() method
	auto ifFind = numbers.find(30);
	if (ifFind != numbers.end())
	{
		std::cout << "Found " << *ifFind << std::endl;
	}

	//count() is a weird name for this function in this context because it will
	//only return 1 or 0. 1 being if the count is 1. There cant possibly be a
	//higher count that 1 in a set.
	if (numbers.count(30))
	{
		std::cout << "Found " << *ifFind << std::endl;
	}



	std::set<Test> tests;
	tests.insert(Test(10, "Mike"));
	tests.insert(Test(30, "Joe")); 
	tests.insert(Test(20, "Sue"));

	//this will do nothing. We are only comparing the name in the 
	//operator overload. The set will see Joe is already in the set and
	//discard the insert rather than updating the data. If we want a 
	//second Joe with a different id, we must compare the id in the 
	//operator overload as well.
	tests.insert(Test(3333, "Joe"));

	for (auto it = tests.begin();it != tests.end();++it)
	{
		it->print();
	}

	return 0;
}