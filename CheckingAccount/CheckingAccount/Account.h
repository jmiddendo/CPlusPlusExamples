#include <string>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double = 0.0, string = "", string = "");
	int withdraw();
	int deposit();
	int getBalance();
	bool login();
	int menu();
	bool currCust();
	void setAccount();
	void setPin();
	void setAccount(string);
	void setPin(string);



private:
	double balance;
	string pin;
	string account;
};

#endif