#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const string tblExisting = "tblExisting.txt", tbThisYear = "tbThisYear.txt", tblNoReturn = "tblNoReturn.txt", tblNew = "tblNew.txt",
tblReturn = "tblReturn.txt";

void restorePreviousYear();
void uploadNewData();
void createNewFiles(set<int>&, vector<int>&, vector<int>&);
void viewFiles();

int main()
{

	char response = '0';

	do
	{
		system("cls");

		cout << "Main Menu:" << endl
			<< "     1 - Recover last years files" << endl
			<< "     2 - Upload New Data" << endl
			<< "     3 - Veiw Data" << endl
			<< "     4 - Exit Application" << endl
			<< "Please make a selection: ";
		cin >> response;

		if (!isdigit(response))
			response = '0';

		switch (response)
		{
		case '1':
			restorePreviousYear();
			break;
		case '2':
			uploadNewData();
			break;
		case '3':
			viewFiles();
			break;
		default:
			break;
		}

		cout << "\nDo you want to run again? (1 == Yes): ";
		cin >> response;

		if (!isdigit(response))
			response = '1';
		else if (int(response) - '0' < 1 || int(response) - '0' > 1)
			response = '0';

	} while (int(response) - '0');

	cout << endl << endl;
	system("pause");
	return 0;

}

void restorePreviousYear()
{

	ofstream oFile;

	oFile.open(tblExisting.c_str());

	if (oFile.fail())
	{
		cout << "Could not open the existing file.";
		system("pause");
		exit(1);
	}

	for (int x = 1; x <= 5; x++)
		oFile << x << endl;

	oFile.close();

	oFile.open(tbThisYear.c_str());

	if (oFile.fail())
	{
		cout << "Could not open the current year file.";
		system("pause");
		exit(1);
	}

	for (int x = 4; x <= 8; x++)
		oFile << x << endl;

	oFile.close();
}

void uploadNewData()
{
	set<int>  existMemNew;
	vector<int>  existMem, TYMem;
	ofstream oFile;
	ifstream iFileTY, iFileEx;
	int ID = 0;

	iFileTY.open(tbThisYear.c_str());

	if (iFileTY.fail())
	{
		cout << "Could not open this year's file.";
		system("pause");
		exit(1);
	}

	iFileEx.open(tblExisting.c_str());

	if (iFileEx.fail())
	{
		cout << "Could not open the existing file.";
		system("pause");
		exit(1);
	}

	while (iFileTY >> ID)
	{
		existMem.push_back(ID);
		existMemNew.insert(ID);
	}

	while (iFileEx >> ID)
	{
		TYMem.push_back(ID);
		existMemNew.insert(ID);
	}

	iFileTY.close();
	iFileEx.close();

	sort(existMem.begin(), existMem.end());
	sort(TYMem.begin(), TYMem.end());

	createNewFiles(existMemNew, existMem, TYMem);

	return;
}

void createNewFiles(set<int>& existMemNew, vector<int>& existMem, vector<int>& TYMem)
{

	int TYLow = 0, EMHigh = 0;
	ofstream oFile;
	set<int> newMem;
	set<int> retMem;
	set<int> noRetMem;

	TYLow = existMem.front();
	EMHigh = TYMem.back();

	oFile.open(tblExisting.c_str());

	if (oFile.fail())
	{
		cout << "Could not open File!";
		system("pause");
		exit(1);
	}


	for (set<int>::iterator it = existMemNew.begin(); it != existMemNew.end(); ++it)
	{
		if (*it < TYLow)
			noRetMem.insert(*it);
		else if (*it >= TYLow && *it <= EMHigh)
			retMem.insert(*it);
		else
			newMem.insert(*it);

		oFile << *it << endl;
	}

	oFile.close();

	oFile.open(tblNoReturn.c_str());

	if (oFile.fail())
	{
		cout << "Could not open File!";
		system("pause");
		exit(1);
	}

	for (set<int>::iterator it = noRetMem.begin(); it != noRetMem.end(); ++it)
	{
		oFile << *it << endl;
	}

	oFile.close();
	oFile.open(tblReturn.c_str());

	if (oFile.fail())
	{
		cout << "Could not open File!";
		system("pause");
		exit(1);
	}

	for (set<int>::iterator it = retMem.begin(); it != retMem.end(); ++it)
	{
		oFile << *it << endl;
	}

	oFile.close();
	oFile.open(tblNew.c_str());

	if (oFile.fail())
	{
		cout << "Could not open File!";
		system("pause");
		exit(1);
	}

	for (set<int>::iterator it = newMem.begin(); it != newMem.end(); ++it)
	{
		oFile << *it << endl;
	}

	oFile.close();

	return;
}

void viewFiles()
{

	ifstream iFile;
	int ID = 0;

	iFile.open(tblNew.c_str());

	if (iFile.fail())
	{
		cout << "File did not open.";
		system("pause");
		exit(1);
	}

	cout << "New members: " << endl;

	while (iFile >> ID)
		cout << ID << endl;

	cout << endl << endl;
	iFile.close();


	iFile.open(tblReturn.c_str());

	if (iFile.fail())
	{
		cout << "File did not open.";
		system("pause");
		exit(1);
	}

	cout << "Returning members: " << endl;

	while (iFile >> ID)
		cout << ID << endl;

	cout << endl << endl;
	iFile.close();

	iFile.open(tblNoReturn.c_str());

	if (iFile.fail())
	{
		cout << "File did not open.";
		system("pause");
		exit(1);
	}

	cout << "Non-Returning members: " << endl;

	while (iFile >> ID)
		cout << ID << endl;

	cout << endl << endl;
	iFile.close();

	return;
}