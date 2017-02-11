#ifndef SimpleCalculator_H
#define SimpleCalculator_H

class SimpleCalculator
{
public:
	SimpleCalculator(double ans = 0.0)
	{
		answer = ans;
	}
	double add(double, double);
	double subtract(double, double);
	double multiply(double, double);
	double divide(double, double);
	double getAnswer();

private:
	double answer;
};

#endif