///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <map>
#include <string>

//maps allow you to associate a data type with a key of a different type
int main()
{
	std::map<std::string, int> ages;

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vickey"] = 30;

	//this will overwrite the origional "Mike" key
	ages["Mike"] = 70;


	//maps contain pairs
	std::pair<std::string, int>addToMap("Peter", 80);
	ages.insert(addToMap);
	ages.insert(std::pair<std::string, int>("Steve", 66));

	//to check if a key is in the map, you must use the find() function.
	//If you simply check by attempting to use the key, even if its not in
	//the map, it will be added simply because you attempted to use it.
	//example: std::cout<<ages["NotInMap"]; 
	//this will display a value of 0. "NotInMap" has now been added to the map.
	if (ages.find("Vickey") != ages.end())
	{
		std::cout << "Found Vickey" << std::endl;
	}
	else
	{
		std::cout << "key not found" << std::endl;
	}


	for (auto it = ages.begin(); it != ages.end(); ++it)
	{
		std::pair <std::string, int> age = *it;

		std::cout << age.first << ": " << age.second << std::endl;
	}

	std::cout << std::endl;
	for (auto it = ages.begin(); it != ages.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
	return 0;
}