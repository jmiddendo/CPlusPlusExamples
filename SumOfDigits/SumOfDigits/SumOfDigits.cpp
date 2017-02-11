#include <iostream>
using namespace std;

int DigitSum(int&, int);
int SingleDigit(int&, int);

int main()
{

	int num = 999;
	int retVal = 0, Question2 = 0;

	cout << "The answer for question 1 is : " << DigitSum(retVal, num) << endl;
	cout << "The answer for question 2 is : " << SingleDigit(Question2, num) << endl;

	cout << endl << endl;
	system("pause");
	return 0;

}

int DigitSum(int& ans, int arg)
{

	int temp, oneDigit;

	temp = arg / 10;
	oneDigit = arg - (temp * 10);

	if (arg < 10)
	{
		ans += arg;
		return ans;
	}
	else
	{
		ans += oneDigit;
		DigitSum(ans, arg / 10);
	}

}

int SingleDigit(int& ans, int arg)
{

	int tempAns = 0, tempArg = DigitSum(tempAns, arg), temp, oneDigit;

	temp = tempArg / 10;
	oneDigit = tempArg - (temp * 10);

	if (tempArg < 10)
	{
		ans += tempArg;
		return ans;
	}
	else
	{
		ans += oneDigit;
		SingleDigit(ans, tempArg / 10);
	}

}