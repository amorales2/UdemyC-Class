///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Test
{
private:
	int id;
	std::string name;

public:
	Test(int id, std::string name) :
		name(name),
		id(id)
	{

	}

	void print()
	{
		std::cout << id << ": " << name << std::endl;
	}

	/*bool operator<(const Test &other) const
	{
		return name < other.name;
	}*/

	friend bool comp(const Test &a, const Test&b);
};

//comparaitor function
bool comp(const Test &lhs, const Test &rhs)
{
	return lhs.name < rhs.name;
}

int main()
{
	std::vector<Test> tests;
	tests.push_back(Test(3, "Vicky"));
	tests.push_back(Test(5, "Mike"));
	tests.push_back(Test(10, "Sue"));
	tests.push_back(Test(7, "Raj"));
	

	
	std::sort(tests.begin(), tests.end(),comp);
	for (int i = 0;i < tests.size();++i)
	{
		tests[i].print();
	}

	return 0;
}