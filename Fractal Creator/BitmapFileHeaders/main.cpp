///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"

int main()
{
	const int  WIDTH = 800;
	const int  HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);
	double min = 9999;
	double max = -9999;
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			double xFractal = (x - WIDTH/2) * 2.0 / WIDTH;
			double yFractal = (y - HEIGHT/2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			std::uint8_t red = (std::uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			bitmap.setPixel(x, y, red, 0, 0);
			if (red < min) min = red;
			if (red > max) max = red;
		}
	}

	if (bitmap.write("test.bmp"))
		std::cout << min << ", " << max << std::endl;
	return 0;
}
