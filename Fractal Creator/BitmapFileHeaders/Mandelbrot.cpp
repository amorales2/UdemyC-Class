///////////////////////////////////////////////////////////////////////////////
//Mandelbrot.cpp
//

#include "Mandelbrot.h"
#include <complex>

int Mandelbrot::getIterations(double x, double y)
{
	std::complex<double> z = 0;
	std::complex<double> c(x,y);
	int iterations = 0;

	//cutoff before reaching infinity
	while (iterations < MAX_ITERATIONS)
	{
		z = z*z + c;

		//magnitude of the complex number
		if (std::abs(z) > 2)
		{
			break;
		}

		++iterations;
	}

	return iterations;
}
