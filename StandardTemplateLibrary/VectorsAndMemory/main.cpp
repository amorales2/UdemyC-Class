///////////////////////////////////////////////////////////////////////////////
//main.cpp
//


//This program demonstrates the way vectors increase capacity as more elements 
//are added. Vectors are implemented with arrays and when more capacity is
//needed, a new array is created and the old data is copied to the new array.
#include <iostream>
#include <vector>

int main()
{
	std::vector<double> numbers(20, 1.0);

	std::cout << "Size: " << numbers.size() << std::endl;


	int capacity = numbers.capacity();
	std::cout << "Capacity: " << capacity << std::endl;

	for (int i = 0;i < 10000;++i)
	{

		if (numbers.capacity() != capacity)
		{
			capacity = numbers.capacity();
			std::cout << "Capacity: " << capacity << std::endl;
		}
		numbers.push_back(i);
	}
	//clear will remove all elements from the vector.
	//The size will become zero, but the previous capacity will remain.

	numbers.clear();
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	//resizing the vector will not effect the capacity either.
	numbers.resize(100);
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	//reserve will increase the size of the vector. Increasing this beyond
	//the previous capacity will cause the capacity to resize to the same ammount.
	numbers.reserve(100000);
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	return 0;
}