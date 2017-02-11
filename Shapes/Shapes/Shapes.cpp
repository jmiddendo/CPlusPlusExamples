#include <iostream>
using namespace std;

int main()
{

	//*********************************************************************************************
	//How to build a triangle
	int num = 0;

	cout << "Please enter a number: ";
	cin >> num;

	for (int x = 0; x < num; x++)
	{
		for (int y = 0; y < num - x; y++)
			cout << "*";

		cout << endl;
	}

	cout << endl;

	//*********************************************************************************************
	//How to build a diamond

	int numrows = 0, med = 0, max = 0, min = 0;

	do
	{
		cout << "Please enter a nummber of rows: ";
		cin >> numrows;
	} while (numrows % 2 == 0);

	med = ((numrows / 2) + 1);
	max = ((numrows / 2) + 1);
	min = ((numrows / 2) + 1);

	for (int x = 1; x <= numrows; x++)
	{
		if (x < med)
		{
			for (int y = 1; y <= numrows; y++)
			{
				if (y >= min && y <= max)
					cout << '*';
				else
					cout << ' ';
			}
			min--;
			max++;
		}
		else if (x == med)
		{
			for (int y = 0; y < numrows; y++)
				cout << '*';

			min++;
			max--;
		}
		else if (x > med)
		{
			for (int y = 1; y <= numrows; y++)
			{
				if (y >= min && y <= max)
					cout << '*';
				else
					cout << ' ';
			}
			min++;
			max--;
		}
		else
			cout << "Unexpected error!";
		cout << endl;
	}

	cout << endl;

	//**************************************************************************************************************
	//How to build a rectangle
	int rows = 0, cols = 0;
	cout << "Please enter a number of rows: ";
	cin >> rows;
	cout << "Please enter a number of columns: ";
	cin >> cols;

	for (int x = 1; x <= rows; x++)
	{
		if (x == 1 || x == rows)
		{
			for (int y = 1; y <= cols; y++)
				cout << '=';
		}
		else
		{
			for (int y = 1; y <= cols; y++)
			{
				if (y == 1 || y == cols)
					cout << '+';
				else
					cout << ' ';
			}
		}
		cout << endl;
	}

	cout << endl << endl;

	system("pause");

	return 0;

}