#include <iostream>
#include <vector>
using namespace std;

void IOInput(vector<int>&, int);

int main()
{
	vector<int> myVec;
	int total = 0;

	IOInput(myVec, total);

	cout << endl << endl;
	system("pause");
	return 0;
}


void IOInput(vector<int>& myVec, int total)
{

	int insVal = 1;

	cout << "Please enter a number: ";
	cin >> insVal;


	if (insVal <= 0)
	{
		int newTotal = 0;
		cout << endl << endl;
		for (int x = myVec.size() - 1; x >= 0; x--)
		{
			newTotal += myVec[x];
			cout << myVec[x] << " Total: " << newTotal << endl;
		}
	}
	else
	{
		total += insVal;
		myVec.push_back(insVal);
		cout << "Total: " << total << endl;
		IOInput(myVec, total);
	}

}