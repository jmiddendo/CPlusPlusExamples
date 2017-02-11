#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
	friend ostream& operator<<(ostream& os, const RationalNumber& rn);

public:
	RationalNumber(int = 0, int = 1); // default constructor
	RationalNumber RationalNumber::operator+(const RationalNumber&);
	RationalNumber RationalNumber::operator-(const RationalNumber&);
	RationalNumber RationalNumber::operator*(const RationalNumber&);
	RationalNumber RationalNumber::operator/(RationalNumber&);


	// relational operators
	bool RationalNumber::operator>(const RationalNumber &) const;
	bool RationalNumber::operator<(const RationalNumber&) const;
	bool RationalNumber::operator>=(const RationalNumber&) const;
	bool RationalNumber::operator<=(const RationalNumber &ler) const;


	// equality operators
	bool RationalNumber::operator==(const RationalNumber &er) const;
	bool RationalNumber::operator!=(const RationalNumber &ner) const;
	void printRational() const; // display rational number


private:
	int numerator; // private variable numerator
	int denominator; // private variable denominator
	void reduction(); // function for fraction reduction
}; // end class RationalNumber


#endif
