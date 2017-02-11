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


void IOInput(vector<int>& myVec, int greatest)
{

	int insVal = 1;

	cout << "Please enter a number: ";
	cin >> insVal;


	if (insVal <= 0)
	{
		cout << endl << endl;
		for (int x = myVec.size() - 1; x >= 0; x--)
		{
			cout << myVec[x] << endl;
		}

		cout << "The greatest is " << greatest << endl;
	}
	else
	{
		if (insVal > greatest)
			greatest = insVal;

		myVec.push_back(insVal);
		cout << "Greatest: " << greatest << endl;
		IOInput(myVec, greatest);
	}

}