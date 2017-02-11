//Lab 3-1:  Complex.h

#ifndef Complex_H
#define Complex_H

class Complex
{
public:
	Complex(double real = 0, double imaginary = 0);
	Complex operator+(const Complex &right);
	Complex operator-(const Complex &right);
	void Complex::printComplex();
	void setComplexNumber(double rp, double ip);
private:
	double realPart;
	double imaginaryPart;
};
#endif