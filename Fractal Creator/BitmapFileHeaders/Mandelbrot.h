///////////////////////////////////////////////////////////////////////////////
//Mandelbrot.h
//

#pragma once

class Mandelbrot
{
public:
	static const int MAX_ITERATIONS = 1000;

public:
	Mandelbrot() = delete;
	virtual ~Mandelbrot() = delete;

	static int getIterations(double x, double y);
};