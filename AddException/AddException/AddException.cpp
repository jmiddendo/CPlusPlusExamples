#include<iostream>
#include<exception>
using namespace std;

int findSum(int, int, int);

int main()
{

	const int MAX_INT = 40;
	int a, b;


	a = 20;
	b = 26;

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
			throw "You have exceeded max value!";
		else
			retVal = a + b;
	}

	catch (const char* error)
	{
		cout << "\n\nNo sum has been produced\n\n";
		retVal = 0;
	}

	return retVal;

}

