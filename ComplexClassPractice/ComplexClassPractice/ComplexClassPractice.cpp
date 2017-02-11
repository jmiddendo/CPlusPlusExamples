#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
	char answer = 'y';

	do
	{
		Complex a(1, 7), b(9, 2), c(10, 1), d(11, 5), e, f;

		e = (a + b);
		f = (c - d);

		a.printComplex();
		cout << " + ";
		b.printComplex();
		cout << " = ";
		e.printComplex();
		cout << endl;

		c.printComplex();
		cout << " - ";
		d.printComplex();
		cout << " = ";
		f.printComplex();
		cout << endl;

		cout << "Would you like to run again? (Y or y)";
		cin >> answer;

		answer = tolower(answer);

	} while (answer == 'y');

	cout << endl;
	system("pause");
	return 0;
}