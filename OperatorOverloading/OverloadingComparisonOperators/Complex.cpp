///////////////////////////////////////////////////////////////////////////////
//Complex.cpp
//
#include "Complex.h"

Complex::Complex() :
	real(0),
	imaginary(0)
{

}

Complex::Complex(double real, double imaginary) :
	real(real),
	imaginary(imaginary)
{

}

Complex::Complex(const Complex & other)
{
	real = other.real;
	imaginary = other.imaginary;
}

const Complex & Complex::operator=(const Complex & other)
{
	real = other.real;
	imaginary = other.imaginary;
	return *this;
}

bool Complex::operator==(const Complex & other) const
{
	return (real == other.real && imaginary == other.imaginary);
}

bool Complex::operator!=(const Complex & other) const
{
	//this will use the == operator overload
	return !(*this == other);
}

std::ostream & operator<<(std::ostream & out, const Complex & c)
{
	out << "(" << c.getReal() << "," << c.getImagionary() << ")";
	return out;
}

Complex operator+(const Complex & c1, const Complex & c2)
{
	return Complex(c1.getReal() + c2.getReal(), c1.getImagionary() + c2.getImagionary());
}

Complex operator+(const Complex & c1, double d)
{
	return Complex(c1.getReal() + d, c1.getImagionary());
}

Complex operator+(double d, const Complex & c1)
{
	return Complex(c1.getReal() + d, c1.getImagionary());
}
