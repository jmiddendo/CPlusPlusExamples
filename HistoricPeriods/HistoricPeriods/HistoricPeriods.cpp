#include <iostream>
#include "Period.h"
#include <string>
using namespace std;

PeriodName findPeriods(int);
void printName(PeriodName[], int[]);
void printName(PeriodName, PeriodName);
int listRun();
int runAgain();
int rngRun();

int main()
{
	int resp1 = 0;
	int resp2 = 0;

	do
	{
		system("cls");

		do
		{
			cout << "Which process would you like to run?\n"
				<< "     1 - By Range\n"
				<< "     2 - By Series\n"
				<< "Selection?  ";
			cin >> resp1;
		} while ((resp1 < 1) || (resp1 > 2));

		system("cls");

		if (resp1 == 1)
			resp2 = rngRun();
		else
			resp2 = listRun();
	} while (resp2 == 1);

	cout << endl << endl;

	system("pause");

	return 0;
}

PeriodName findPeriods(int searchDate)
{
	PeriodName retVal;

	if (searchDate > 570)
		retVal = Precambrian;
	else if (searchDate <= 570 && searchDate > 500)
		retVal = Cambrian;
	else if (searchDate <= 500 && searchDate > 435)
		retVal = Ordovician;
	else if (searchDate <= 435 && searchDate > 395)
		retVal = Silurian;
	else if (searchDate <= 395 && searchDate > 345)
		retVal = Devonian;
	else if (searchDate <= 345 && searchDate > 280)
		retVal = Carboniferous;
	else if (searchDate <= 280 && searchDate > 225)
		retVal = Permian;
	else if (searchDate <= 225 && searchDate > 192)
		retVal = Triassic;
	else if (searchDate <= 192 && searchDate > 136)
		retVal = Jurassic;
	else if (searchDate <= 136 && searchDate > 65)
		retVal = Cretaceous;
	else if (searchDate <= 65 && searchDate > 23)
		retVal = Paleogene;
	else if (searchDate <= 23)
		retVal = Neogene;

	return retVal;
}

void printName(PeriodName prtArray[], int rngDate[])
{
	int x = 0;
	string retVal = "";

	do
	{

		switch (prtArray[x])
		{
		case 0:
			retVal = "Neogene";
			break;
		case 1:
			retVal = "Paleogene";
			break;
		case 2:
			retVal = "Cretaceous";
			break;
		case 3:
			retVal = "Jurassic";
			break;
		case 4:
			retVal = "Triassic";
			break;
		case 5:
			retVal = "Permian";
			break;
		case 6:
			retVal = "Carboniferous";
			break;
		case 7:
			retVal = "Devonian";
			break;
		case 8:
			retVal = "Silurian";
			break;
		case 9:
			retVal = "Ordovician";
			break;
		case 10:
			retVal = "Cambrian";
			break;
		case 11:
			retVal = "Precambrian";
			break;
		}

		cout << "The period for " << rngDate[x] << " is: " << retVal << endl;
		x++;
	} while (rngDate[x] != '\0');
}

int listRun()
{
	const int SIZE = 101;
	int rngDate[SIZE];
	PeriodName prtArray[SIZE];
	int x = 0, y = 0, kill = 0;


	do
	{
		cout << "Please enter a date (-1 to end): ";
		cin >> rngDate[x];
		if (x == 0 && rngDate[x] == -1)
		{
			cout << "\n\nProcess Aborted!";
			goto wrap;
		}
		else
			x++;
	} while (((rngDate[x - 1] != -1) && (x < SIZE)) || (kill == 1));

	if (kill != 1)
	{
		rngDate[x - 1] = '\0';

		do
		{
			prtArray[y] = findPeriods(rngDate[y]);
			y++;
		} while (rngDate[y] != '\0');

		cout << endl << endl;

		printName(prtArray, rngDate);
	}

wrap:
	cout << endl << endl;

	return runAgain();
}

int runAgain()
{
	int retVal = 0;

	do
	{
		cout << "Do you want to run again? (1 = " << char(34) << "Yes" << char(34) << ", 2 = "
			<< char(34) << "No" << char(34) << ")  ";
		cin >> retVal;

		if ((int(retVal) < 1) || (int(retVal) > 2))
			cout << "\nInvalid Response.  Please try again!\n\n";
	} while ((retVal < 1) || (retVal > 2));

	return retVal;
}

int rngRun()
{

	int beginDate = 0, endDate = 0;
	PeriodName retBegin, retEnd;


	cout << "Please enter a beginning date: ";
	cin >> beginDate;

	do
	{
		cout << "Please enter a ending date: ";
		cin >> endDate;

		if (endDate < beginDate)
			cout << "Invalid End Date!  Please try again!" << endl << endl;

	} while (endDate < beginDate);

	retBegin = findPeriods(beginDate);
	retEnd = findPeriods(endDate);

	cout << endl << endl;

	printName(retBegin, retEnd);

	cout << endl << endl;

	return runAgain();
}

void printName(PeriodName firstPeriod, PeriodName secondPeriod)
{

	int x = int(firstPeriod), y = int(secondPeriod);

	cout << "The periods associated with the period you entered are: " << endl;

	while (x <= y)
	{
		switch (x)
		{
		case 0:
			cout << "     Neogene" << endl;
			break;
		case 1:
			cout << "     Paleogene" << endl;
			break;
		case 2:
			cout << "     Cretaceous" << endl;
			break;
		case 3:
			cout << "     Jurassic" << endl;
			break;
		case 4:
			cout << "     Triassic" << endl;
			break;
		case 5:
			cout << "     Permian" << endl;
			break;
		case 6:
			cout << "     Carboniferous" << endl;
			break;
		case 7:
			cout << "     Devonian" << endl;
			break;
		case 8:
			cout << "     Silurian" << endl;
			break;
		case 9:
			cout << "     Ordovician" << endl;
			break;
		case 10:
			cout << "     Cambrian" << endl;
			break;
		case 11:
			cout << "     Precambrian" << endl;
			break;
		}
		x++;
	}

	return;

}