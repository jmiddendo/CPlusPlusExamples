#include <iostream>
#include "Complex.h"

Complex::Complex(double real, double imaginary)
{
	setComplexNumber(real, imaginary);
}

Complex Complex::operator+(const Complex &right)
{
	Complex tempVal;
	tempVal.realPart = realPart + right.realPart;
	tempVal.imaginaryPart = imaginaryPart + right.imaginaryPart;
	return tempVal;

}

Complex Complex::operator-(const Complex &right)
{
	Complex tempVal;
	tempVal.realPart = this->realPart - right.realPart;
	tempVal.imaginaryPart = this->imaginaryPart - right.imaginaryPart;
	return tempVal;
}

void Complex::printComplex()
{
	std::cout << '(' << realPart << "," << imaginaryPart << ')';
}

void Complex::setComplexNumber(double rp, double ip)
{
	realPart = rp;
	imaginaryPart = ip;
}