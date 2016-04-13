///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string inFileName = "Test.txt";
	std::ifstream inFile;

	//you can use this with std::fstream. using std::ifstream is easier
	//inFile.open(inFileName, std::ios::in);

	inFile.open(inFileName);

	if (inFile.is_open())
	{
		std::string line;
		//using while(inFile) will do the same thing as well. This is 
		//do to the bool operator being overloaded
		while (!inFile.eof())
		{
			std::getline(inFile,line); //under the fstream headder
			std::cout << line << std::endl;
		}
		
		
		inFile.close();//always remember to close the file
	}
	else
	{
		std::cout << "File cannot be opened: " << inFileName << std::endl;
	}
	return 0;
}