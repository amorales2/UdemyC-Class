///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <fstream>
#include <string>
int main()
{
	//std::ofstream outFile;
	std::fstream outFile;

	std::string outputFileName = "text.txt";
	outFile.open(outputFileName);

	if (outFile.is_open())
	{
		outFile << "HelloThere"<<std::endl;
		outFile << 123 << std::endl;
		outFile.close();
	}
	else
	{
		std::cout << "File could not be opened: " << outputFileName << std::endl;
	}
	return 0;
}