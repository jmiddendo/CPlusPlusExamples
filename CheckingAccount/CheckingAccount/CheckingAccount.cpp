#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

int main()
{

	int answer = 0;
	bool valid, notLock = true;

	Account Cust1;

	if (Cust1.currCust())
	{
		Cust1.setAccount("12345");
		Cust1.setPin("1234");
	}
	else
	{
		Cust1.setAccount();
		Cust1.setPin();
	}

	if (Cust1.login())
	{
		answer = 4;
		notLock = false;
	}
	else
	{
		answer = 0;
		notLock = true;
	}

	while (answer != 4)
	{
		answer = Cust1.menu();

		switch (answer)
		{
		case 1:
		{
			answer = Cust1.getBalance();
			break;
		}
		case 2:
		{
			answer = Cust1.deposit();
			break;
		}
		case 3:
		{
			answer = Cust1.withdraw();
			break;
		}
		case 4:
		{
			cout << "Thank you for banking with Middendorf Rocks Banking and Trust.  Please enjoy the rest of your day!" << endl;
			break;
		}
		default:
			cout << "We are experiencing technical diificulties!  Please try again later!";
		}

	}


	if (notLock)
	{
		system("cls");
		cout << "Thank you for banking with Middendorf Rocks Banking and Trust.  Please enjoy the rest of your day!" << endl;
	}
	cout << endl << endl;

	system("pause");

	return 0;

}