#include <string>
#include "Calc.h"
using namespace std;

double SimpleCalculator::add(double a, double b)
{
	answer = a + b;
	return answer;
}

double SimpleCalculator::subtract(double a, double b)
{
	answer = a - b;
	return answer;
}

double SimpleCalculator::multiply(double a, double b)
{
	answer = a * b;
	return a * b;
}

double SimpleCalculator::divide(double a, double b)
{
	if (b != 0)
		answer = a / b;
	else
		answer = 0;

	return answer;
}

double SimpleCalculator::getAnswer()
{
	return answer;
}

