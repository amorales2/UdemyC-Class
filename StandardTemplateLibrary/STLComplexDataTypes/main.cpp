///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

//this is a demonstration of using multiple data structures together to make a
//custom data structure.
//this is a stupid video imo
int main()
{
	std::map<std::string, std::vector<int> > testScores;

	testScores["Mike"].push_back(10);
	testScores["Mike"].push_back(20);
	testScores["Vicky"].push_back(15);

	for (auto it = testScores.begin();it != testScores.end();++it)
	{
		auto name = it->first;
		auto scoreList = it->second;

		std::cout << name << ": " << std::flush;

		for (int i = 0;i < scoreList.size();++i)
		{
			std::cout << scoreList[i] << " " << std::flush;
		}
		std::cout << std::endl;

	}

	return 0;
}