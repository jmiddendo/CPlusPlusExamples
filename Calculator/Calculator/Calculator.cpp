#include <iostream>
#include <string>
#include <exception>
using namespace std;

const int MAX_VAL = 1000;

string convert(string);
bool isValidInt(string);
bool isOperator(string);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);


int main()
{

	cout << "*******************************************************************************"
		<< "\n*                              Calculator                                     *"
		<< "\n*      Enter + for addition.                                                  *"
		<< "\n*      Enter - for subtraction.                                               *"
		<< "\n*      Enter * for multiplication.                                            *"
		<< "\n*      Enter / for division.	    	          			      *"
		<< "\n*      Enter clear to terminate.                                              *"
		<< "\n*      Please note, operator and number together are                          *"
		<< "\n*           not valid (*2 != Multiplied by 2).                                *"
		<< "\n*******************************************************************************" << endl << endl;


	string response;
	string response2;
	int answer = 0;

	do
	{
		cout << "> ";
		cin >> response;

		if (isValidInt(response))
		{
			answer = atoi(response.c_str());
			cout << "The total is: " << answer;
		}
		else if (isOperator(response))
		{
			do
			{
				cout << "> ";
				cin >> response2;

				if (convert(response2) == "CLEAR")
					break;

				if (!isValidInt(response2))
					cout << "Invalid Response!" << endl;

			} while (!isValidInt(response2));

			if (convert(response2) == "CLEAR")
			{
				cout << "\nThank you.  Have a nice day!" << endl;
				break;
			}
			else
			{
				switch (response.at(0))
				{
				case '+':
					answer = add(answer, atoi(response2.c_str()));
					break;
				case '-':
					answer = subtract(answer, atoi(response2.c_str()));
					break;
				case '*':
					answer = multiply(answer, atoi(response2.c_str()));
					break;
				case '/':
					answer = divide(answer, atoi(response2.c_str()));
					break;
				default:
					cout << "Unexpected error.  Please try again!" << endl;
					break;
				}

				cout << "The total is: " << answer;
			}
		}
		else if (convert(response) == "CLEAR")
			cout << "\nThank you.  Have a nice day!" << endl;
		else
		{
			cout << "Invalid Response!" << endl;
			cout << "The total is: " << answer;
		}

		cout << endl;

	} while (convert(response) != "CLEAR");

	cout << endl << endl;

	system("pause");

	return 0;

}

string convert(string resp)
{

	for (int x = 0; x < resp.length(); x++)
	{
		resp[x] = toupper(resp[x]);
	}

	return resp;
}


bool isValidInt(string str)
{
	int start = 0;
	int i;
	bool valid = true;
	bool sign = false;

	if (int(str.length()) == 0) valid = false;

	if (str.at(0) == '-' || str.at(0) == '+')
	{
		sign = true;
		start = 1;
	}

	if (sign && int(str.length()) == 1) valid = false;

	i = start;
	while (valid && i < int(str.length()))
	{
		if (!isdigit(str.at(i))) valid = false;
		i++;
	}

	return valid;
}

bool isOperator(string str)
{

	bool sign = false;

	if (str.at(0) == '-' || str.at(0) == '+' || str.at(0) == '*' || str.at(0) == '/')
		sign = true;


	if (sign && int(str.length()) == 1)
		return true;
	else
		return false;

}

int add(int tot, int num)
{
	try
	{
		if (tot > MAX_VAL - num || num > MAX_VAL - tot)
			throw "Maximum value exceeded!  Please try again!";
		else
		{
			tot += num;
			return tot;
		}

	}
	catch (char* error)
	{
		cout << error << endl;
		return tot;
	}

}

int subtract(int tot, int num)
{

	try
	{
		if (tot < num - MAX_VAL || num < tot - MAX_VAL)
			throw "Maximum value exceeded!  Please try again!";
		else
		{
			tot -= num;
			return tot;
		}

	}
	catch (char* error)
	{
		cout << error << endl;
		return tot;
	}
}

int multiply(int tot, int num)
{

	try
	{
		if (tot == 0 || num == 0)
		{
			tot = 0;
			return tot;
		}
		else if (tot < 0)
		{
			if (-tot > MAX_VAL / num || num > MAX_VAL / -tot)
				throw "Maximum value exceeded!  Please try again!";
			else
			{
				tot *= num;
				return tot;
			}
		}
		else if (num < 0)
		{
			if (tot > MAX_VAL / -num || -num > MAX_VAL / tot)
				throw "Maximum value exceeded!  Please try again!";
			else
			{
				tot *= num;
				return tot;
			}
		}
		else if (tot > MAX_VAL / num || num > MAX_VAL / tot)
			throw "Maximum value exceeded!  Please try again!";
		else
		{
			tot *= num;
			return tot;
		}

	}
	catch (char* error)
	{
		cout << error << endl;
		return tot;
	}
}

int divide(int tot, int num)
{
	try
	{
		if (num == 0)
			throw "Cannot divide by zero! Please try again!";
		else
		{
			tot /= num;
			return tot;
		}
	}
	catch (char* error)
	{
		cout << error << endl;
		return tot;
	}

}