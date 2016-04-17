///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool match(std::string test)
{
	//return test == "two";
	return test.size() == 3;
}


int countStrings(std::vector<std::string> &tests,bool (*match)(std::string test))
{
	int count = 0;
	for (auto it = tests.begin();it != tests.end();++it)
	{
		if (match(it->data()))
		{
			++count;
		}
	}
	return count;

}


int main()
{
	std::vector<std::string> texts;

	texts.push_back("one");//true
	texts.push_back("two");//true
	texts.push_back("three");
	texts.push_back("two");//true
	texts.push_back("four");
	texts.push_back("two");//true
	texts.push_back("three");

	std::cout << match("one") << std::endl;
	std::cout << match("oned") << std::endl;

	//pass match as the comparitor function
	std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl;
	

	//using our own function 
	std::cout << std::endl;
	std::cout << countStrings(texts,match) << std::endl;
	return 0;
}