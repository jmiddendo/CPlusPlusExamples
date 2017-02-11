#include<iostream>
#include <string>
#include<exception>
using namespace std;

class sumError{};

int findSum(int, int, int);

int main()
{

	const int MAX_INT = 40;
	int a, b;

	a = 22;
	b = 19;

	cout << findSum(a, b, MAX_INT);

	cout << endl << endl;

	system("pause");

	return 0;

}

int findSum(int a, int b, int MAX)
{

	int retVal;

	try
	{
		if (a > MAX - b || b > MAX - a)
			throw sumError();
		else
			retVal = a + b;
	}

	catch (sumError)
	{
		cout << "\n\nNo sum has been produced\n\n";
		retVal = 0;
	}

	return retVal;

}

int sumError()
{
	cout << "Please try again!" << endl;
	return 1;
}