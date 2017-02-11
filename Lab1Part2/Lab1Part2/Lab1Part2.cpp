//Lab 1: stringCompare.cpp

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int stringCompare1(char[], char[]);
int stringCompare2(char *, char *);

int main()
{
	char string1[100], string2[100];

	cout << "Enter two strings: ";
	cin >> string1 >> string2;

	//char *str_ptr1 = &string1[0], *str_ptr2 = &string2[0];

	cout << "The value returned from stringCompare1( \"" << string1
		<< "\", \"" << string2 << "\" ) is "
		<< stringCompare1(string1, string2)
		<< "\nThe value returned from stringCompare2( \"" << string1
		<< "\", \"" << string2 << "\" ) is "
		<< stringCompare2(string1, string2)
		<< endl;

	system("pause");

	return 0;
}

int stringCompare1(char s1[], char s2[])
{

	int index;

	for (index = 0; index < 100; index++)
	{
		if (s1[index] != s2[index] || (s1[index] == '\0' && s2[index] == '\0'))
			break;
	}

	if (s1[index] == '\0' && s2[index] == '\0')
		return 0;
	else if (s1[index] > s2[index])
		return 1;
	else
		return -1;
}

int stringCompare2(char *s1, char *s2)
{
	int index;

	for (index = 0; index < 100; index++)
	{
		if (*(s1 + index) != *(s2 + index) || (*(s1 + index) == '\0' && *(s2 + index) == '\0'))
			break;
	}

	if (*(s1 + index) == '\0' && *(s2 + index) == '\0')
		return 0;
	else if (*(s1 + index) > *(s2 + index))
		return 1;
	else
		return -1;

}