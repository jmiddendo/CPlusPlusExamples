// RationalNumber test program.
#include <iostream> 
#include<cstdlib>
using namespace std;
#include "RationalNumber.h"

int main()
{

	char response = 'Y';

	while (toupper(response) == 'Y')
	{

		system("cls");

		int num1 = 0, num2 = 0, den1 = 0, den2 = 0;

		cout << "Please enter the first numerator: ";
		cin >> num1;
		cout << "Please enter the first denominator: ";
		cin >> den1;

		cout << "Please enter the second numerator: ";
		cin >> num2;
		cout << "Please enter a second denominator: ";
		cin >> den2;

		system("cls");

		RationalNumber c(num1, den1), d(num2, den2), x;

		//cout << c << ' + '  endl;

		x = c + d;
		cout << c << " + " << d << " = " << x << endl;

		x = c - d;
		cout << c << " - " << d << " = " << x << endl;

		x = c * d;
		cout << c << " * " << d << " = " << x << endl;

		x = c / d;
		cout << c << " / " << d << " = " << x << endl << endl;


		cout << '\n' << c << " is:\n";

		// test overloaded greater than operator
		cout << ((c > d) ? "  > " : "  <= ") << d << " according to the overloaded > operator\n";

		// test overloaded less than operator
		cout << ((c < d) ? "  < " : "  >= ") << d << " according to the overloaded < operator\n";

		// test overloaded greater than or equal to operator
		cout << ((c >= d) ? "  >= " : "  < ") << d << " according to the overloaded >= operator\n";

		// test overloaded less than or equal to operator
		cout << ((c <= d) ? "  <= " : "  > ") << d << " according to the overloaded <= operator\n";

		// test overloaded equality operator
		cout << ((c == d) ? "  == " : "  != ") << d << " according to the overloaded == operator\n";

		// test overloaded inequality operator
		cout << ((c != d) ? "  != " : "  == ") << d << " according to the overloaded != operator" << endl << endl;

		cout << "Do you want to run again?";
		cin >> response;


	}

	cout << endl << endl;

	system("PAUSE");

	return 0;
} // end main
