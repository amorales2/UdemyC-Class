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
	void print() const
	{
		std::cout << name << ": " << age << std::flush;
	}

	//operator overload
	//should be const as it wont change either this or the other object whatsoever
	bool operator<(const Person &other) const
	{
		if (name == other.name)
		{
			return age < other.age;
		}
		return name < other.name;
	}
};
int main()
{
	std::map<Person,int> people;
	
	people[Person("Sue", 30)] = 30;
	people[Person("Raj", 20)] = 20;
	people[Person("Mike", 40)] = 40;

	//this will update the value in the map 
	people[Person("Mike", 40)] = 30;
	
	//because of how we overloaded the < operator, only the name is taken into
	//account when making the comparison. This means, that even though the age
	//is different, the map still thinks the key is the same so it simply updates
	//the value associated with the origional "Mike" key. In order to also compare
	//the age, we need to add that to the operator overload we created.
	people[Person("Mike", 444)] = 123;

	//iterators are returned as const to prevent from being modified and chaning
	//where they are in the map. Because of this, the function print() must be 
	//marked const in order for us to be able to use it.
	for (auto it = people.begin();it != people.end();++it)
	{
		std::cout << it->second << ": " << std::flush;
		it->first.print();
		std::cout << std::endl;
	}


	return 0;
}