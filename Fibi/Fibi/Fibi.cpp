#include <iostream>
using namespace std;

int Fib(int);

int main()
{
	int num = 0;

	cout << "Please enter the number you want to see: ";
	cin >> num;

	for (int x = 0; x <= num; x++)
		cout << "The " << x << " fibonacci number is " << Fib(x) << endl;

	cout << endl;
	system("pause");
	return 0;

}

int Fib(int number)
{

	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else
		return (Fib(number - 1) + Fib(number - 2));
}
