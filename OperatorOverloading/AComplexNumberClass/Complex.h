///////////////////////////////////////////////////////////////////////////////
//Complex.h
//

#pragma once
#include <ostream>

class Complex
{
private:
	double real;
	double imaginary;


public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);

	//operator overload
	const Complex &operator = (const Complex &other);
	
	//get functions
	double getReal() const { return real; }
	double getImagionary() const{ return imaginary; }
};

std::ostream &operator << (std::ostream &out, const Complex &c);