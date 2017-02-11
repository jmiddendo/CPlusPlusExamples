#include <iostream>
#include "Calc.h"
using namespace std;

int main()
{

	double num1 = 0, num2 = 0;
	SimpleCalculator sc;


	cout << "Please enter a number: ";
	cin >> num1;
	cout << "Please enter a second number: ";
	cin >> num2;

	cout << "The the value of answer at the start is " << sc.getAnswer() << endl;

	double answerAdd = sc.add(num1, num2);
	double answerSubt = sc.subtract(num1, num2);
	double answerMult = sc.multiply(num1, num2);
	double answerDiv = sc.divide(num1, num2);

	cout << "The sum of the numbers is " << answerAdd << endl;
	cout << "The difference between the numbers is " << answerSubt << endl;
	cout << "The product of the two numbers is " << answerMult << endl;
	cout << "The quotient of the two numbers is " << answerDiv << endl;
	cout << "The the value of answer at the end is " << sc.getAnswer() << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}