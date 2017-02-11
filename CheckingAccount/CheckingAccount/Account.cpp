#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

Account::Account(double bal, string pin_num, string acct)
{
	balance = bal;
	pin = pin_num;
	account = acct;
}

int Account::deposit()
{
	double amt = 0.0;
	char answer;

	cout << "Please enter a deposit amount: ";
	cin >> amt;

	balance += amt;

	cout << "The amount has been added into you account!" << endl << endl;

	cout << "Would you like to perform another transaction? (Y or y): ";
	cin >> answer;

	if (answer == 'Y' || answer == 'y')
		return 0;
	else
		return 4;
}

int Account::withdraw()
{
	double amt = 0.0;
	char answer;

	cout << "Please enter a withdraw amount: ";
	cin >> amt;

	if (amt <= balance && balance > 0)
	{
		balance -= amt;
		cout << "\nThe amount has been withdrawn from your account";
	}
	else
		cout << "\nInsufficient funds! Please check your register and try again!";

	cout << "\n\nWould you like to perform another transaction? (Y or y): ";
	cin >> answer;

	if (answer == 'Y' || answer == 'y')
		return 0;
	else
		return 4;

}

int Account::getBalance()
{
	char answer = 0;

	cout << "The balance of your account is " << balance << endl << endl;

	cout << "Would you like to perform another transaction? (Y or y): ";
	cin >> answer;

	if (answer == 'Y' || answer == 'y')
		return 0;
	else
		return 4;
}

bool Account::login()
{
	string acct, pin_num;
	int hack_check = 0;

	do
	{

		if (hack_check >= 3)
		{
			system("cls");
			cout << "Exceeded number of login attempts!  The account has been locked.  Please contact customer service at 1-800-Fake-Num." << endl;
			return true;
			break;
		}

		cout << "Please enter a account and pin!" << endl;
		cout << "     Account: ";
		cin >> acct;
		cout << "     Pin: ";
		cin >> pin_num;

		system("cls");

		if ((account != acct) || (pin != pin_num))
		{
			cout << "The account number or pin is incorrect!  Please try again." << endl;
			hack_check++;
		}
	} while ((account != acct) || (pin != pin_num));

	system("cls");

	return false;

}

int Account::menu()
{
	int answer = 0;

	system("cls");

	do
	{
		cout << "Please chose from the following options: "
			<< "\n     1 - View Account Balance"
			<< "\n     2 - Make Deposit"
			<< "\n     3 - Make Withdraw"
			<< "\n     4 - Exit Banking"
			<< "\nWhat would you like to do: ";
		cin >> answer;

		if (answer < 1 || answer > 4)
		{
			system("cls");
			cout << "I'm sorry.  I did not recognize you selection.  Please try again!" << endl;
		}

	} while (answer < 1 || answer > 4);

	system("cls");

	return answer;
}

bool Account::currCust()
{

	string response;

	cout << "Are you a current customer? (Y or y): ";
	cin >> response;

	system("cls");

	if (response == "Y" || response == "y")
		return true;
	else
		return false;
}


void Account::setAccount()
{
	string acct;

	do
	{
		cout << "Please enter a five digit account number: ";
		cin >> acct;

		if (acct.length() != 5)
			cout << "Error! Please try again!";
	} while (acct.length() != 5);

	account = acct;

	system("cls");

	return;
}
void Account::setPin()
{

	string pin_num;

	do
	{
		cout << "Please enter a four digit pin number: ";
		cin >> pin_num;

		if (pin_num.length() != 4)
			cout << "Error! Please try again!";
	} while (pin_num.length() != 4);

	pin = pin_num;

	system("cls");

	return;

}

void Account::setAccount(string acct)
{

	account = acct;

	system("cls");

	return;
}
void Account::setPin(string pin_num)
{
	pin = pin_num;

	system("cls");

	return;
}