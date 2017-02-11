//Header file for class IntegerSet
#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
public:
	//default constructor
	IntegerSet()
	{
		emptySet();
	}//end IntegerSet constructor
	IntegerSet(int[], int);  //constructor that takes an initial set
	IntegerSet unionOfSets(const IntegerSet&);
	IntegerSet intersectionOfSets(const IntegerSet&);
	void emptySet();
	void inputSet();
	void insertElement(int);
	void deleteElement(int);
	void printSet() const;
	bool isEqualTo(const IntegerSet &) const;
	void sortArray();


private:
	int set[101];
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	}
};

#endif