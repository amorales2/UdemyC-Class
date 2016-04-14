///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <vector>

int main()
{

	//this is a vector of int vectors.
	//3 rows, 4 cols
	std::vector< std::vector<int> > grid(3 , std::vector<int>(4,7) );

	//this adds an extra element to the end of the second row.
	grid[1].push_back(8);

	for (int row = 0;row < grid.size();++row)
	{
		for (int col = 0;col < grid[row].size();++col)
		{

			//2d vectors can be accessed like this because grid[row] will 
			//evaluate to a vector itself. You can then get the elements from
			//the grid[row] vector by using the square brackets just like
			//in a 2d array.
			std::cout << grid[row][col] << std::flush;
		}

		std::cout << std::endl;
	}

	return 0;
}