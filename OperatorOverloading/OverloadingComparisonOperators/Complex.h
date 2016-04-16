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
	bool operator ==(const Complex &other) const;
	bool operator !=(const Complex &other) const;

	//get functions
	double getReal() const { return real; }
	double getImagionary() const { return imaginary; }
};

std::ostream &operator << (std::ostream &out, const Complex &c);
Complex operator + (const Complex &c1, const Complex &c2);

//this will allow object+double but not the other way around
Complex operator + (const Complex &c1, double d);

//this will allow double+object
Complex operator + (double d, const Complex &c1);