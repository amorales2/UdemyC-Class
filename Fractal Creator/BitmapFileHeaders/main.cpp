///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include "Bitmap.h"


int main()
{
	const int  WIDTH = 800;
	const int  HEIGHT = 800;

	Bitmap bitmap(WIDTH, HEIGHT);

	bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 255, 255, 255);

	for (int y = 0; y < HEIGHT; ++y)
		for (int x = 0; x < WIDTH; ++x)
		{
			bitmap.setPixel(x, y, 255, 0, 0);
		}


	if (bitmap.write("test.bmp"))
		std::cout << "Finished" << std::endl;
	return 0;
}
