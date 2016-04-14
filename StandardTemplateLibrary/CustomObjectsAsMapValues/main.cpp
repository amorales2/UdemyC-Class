///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <map>
#include <string>


class Person
{
private:
	std::string name;
	int age;
public:

	//in order to use a custom class object with a map, a defaul constructor is
	//required. Maps call the default constructor of a class first and then you
	//can assign data to it.
	Person() :
		name(""),
		age(0)
	{

	}

	//copy constructor
	//provided by default in C++. Default copy constructor is a simple 1:1 shadow
	//copy of all the elements of one object to another.
	Person(const Person &other)
	{
		std::cout << "Copy Constructor Running" << std::endl;
		name = other.name;
		age = other.age;
	}

	Person(std::string name, int age) :
		name(name),
		age(age)
	{

	}
	void print()
	{
		std::cout << name << ": " << age << std::endl;
	}

};
int main()
{
	std::map<int,Person> people;

	people[0] = Person("Mike", 40);
	people[1] = Person("Vickey", 30);
	people[2] = Person("Roj", 20);

	people.insert(std::make_pair(55, Person("Bob", 45)));
	people.insert(std::make_pair(3, Person("Sue", 24)));

	for (auto it = people.begin();it != people.end();++it)
	{
		std::cout << it->first << ": " << std::flush;
		it->second.print();
	}


	return 0;
}