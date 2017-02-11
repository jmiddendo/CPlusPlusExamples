#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using namespace std;

void addVal(stack<int>&);
void subtVal(stack<int>&);
void multiVal(stack<int>&);
void divVal(stack<int>&);


int main()
{

	string exp = "345+-2*";

	cout << "Please enter an equation: ";
	cin >> exp;

	stack<int> mystack;

	for (int i = 0; i < exp.size(); i++)
	{

		if (isdigit(exp.at(i)))
			mystack.push(exp.at(i) - '0');
		else
		{
			switch (exp.at(i))
			{
			case '+':
			{
				try
				{
					if (mystack.size() < 2)
						throw "There is an error with the equation.";
					else
					{
						addVal(mystack);
						break;
					}
				}
				catch (char* err)
				{
					cout << err << endl;
					system("pause");
					exit(1);
				}
			}
			case '-':
			{
				try
				{
					if (mystack.size() < 2)
						throw "There is an error with the equation.";
					else
					{
						subtVal(mystack);
						break;
					}
				}
				catch (char* err)
				{
					cout << err << endl;
					system("pause");
					exit(1);
				}
			}
			case '*':
			{
				try
				{
					if (mystack.size() < 2)
						throw "There is an error with the equation.";
					else
					{
						multiVal(mystack);
						break;
					}
				}
				catch (char* err)
				{
					cout << err << endl;
					system("pause");
					exit(1);
				}
			}
			case '/':
			{

				try
				{
					if (mystack.size() < 2)
						throw "There is an error with the equation.";
					else
					{
						divVal(mystack);
						break;
					}
				}
				catch (char* err)
				{
					cout << err << endl;
					system("pause");
					exit(1);
				}
			}
			default:
			{
				cout << "Wrong" << endl;
				system("pause");
				exit(1);
			}
			}

		}

	}

	cout << mystack.top();

	std::cout << endl << endl;

	system("pause");

	return 0;
}


void addVal(stack<int>& stk)
{
	int temp = 0, temp1 = 0;

	temp = stk.top();
	stk.pop();
	temp1 = stk.top();
	stk.pop();
	stk.push(temp + temp1);
}

void subtVal(stack<int>& stk)
{
	int temp = 0, temp1 = 0;

	temp = stk.top();
	stk.pop();
	temp1 = stk.top();
	stk.pop();
	stk.push(temp - temp1);
}

void multiVal(stack<int>& stk)
{
	int temp = 0, temp1 = 0;

	temp = stk.top();
	stk.pop();
	temp1 = stk.top();
	stk.pop();
	stk.push(temp * temp1);
}

void divVal(stack<int>& stk)
{
	int temp = 0, temp1 = 0;

	temp = stk.top();
	stk.pop();
	temp1 = stk.top();
	stk.pop();

	if (temp1 == 0)
		stk.push(0);
	else
		stk.push(temp / temp1);
}