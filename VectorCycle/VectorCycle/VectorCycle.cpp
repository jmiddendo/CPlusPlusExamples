#include <iostream>
#include <vector>
using namespace std;

void IOInput(vector<int>&);

int main()
{
	vector<int> myVec;

	IOInput(myVec);

	cout << endl << endl;
	system("pause");
	return 0;
}

void IOInput(vector<int>& myVec)
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
	}
	else
	{
		myVec.push_back(insVal);
		IOInput(myVec);
	}

}