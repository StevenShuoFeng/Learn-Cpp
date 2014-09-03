// excercise 6.11
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

///////////////////////////////////////////////////
class fraction{
	long num; // numerator
	long den; // denominator
public:
	fraction() : num(0), den(1)
	{}
	fraction(int n, int d) : num(n), den(d)
	{}
	void setFraction();
	void showFraction();
	void lowterms();
	fraction lowterms(fraction f) const; // change the fraction to lowest terms
	fraction operator + (fraction f2) const; 
	fraction operator - (fraction f2) const;
	fraction operator * (fraction f2) const;
	fraction operator / (fraction f2) const;
	bool operator == (fraction f2) const;
	bool operator != (fraction f2) const;
};
void fraction::setFraction(){
	char ch;
	cout << "Type in your fraction in form of a/b" << endl;
	cin >> num >> ch >> den;
}
void fraction::showFraction(){
	lowterms();
	cout << num << "/" << den;
}
fraction fraction::operator + (fraction f2) const
{ // f1 + f2
	long n = num * f2.den + den * f2.num;
	long d = den * f2.den;
	fraction tmp(n,d);
	return tmp.lowterms(tmp);
}
fraction fraction::operator - (fraction f2) const
{ // f1 + f2
	long n = num * f2.den - den * f2.num;
	long d = den * f2.den;
	fraction tmp(n,d);
	return tmp.lowterms(tmp);
}
fraction fraction::operator * (fraction f2) const
{ // f1 + f2
	long n = num * f2.num;
	long d = den * f2.den;
	fraction tmp(n,d);
	return tmp.lowterms(tmp);
}
fraction fraction::operator / (fraction f2) const
{ // f1 + f2
	long n = num*f2.den;
	long d = den * f2.num;
	fraction tmp(n,d);
	return tmp.lowterms(tmp);
}

void fraction::lowterms() // change ourself to lowest terms
{
	long tnum, tden, temp, gcd;
	tnum = labs(num); // use non-negative copies
	tden = labs(den); // (needs cmath)
	if (tden == 0) // check for n/0
	{
		cout << "Illegal fraction : division by 0"; exit(1);
	}
	else if (tnum == 0) // check for 0/n
	{
		num = 0; den = 1; return;
	}
	// this ¡®while¡¯ loop finds the gcd of tnum and tden
	while (tnum != 0)
	{
		if (tnum < tden) // ensure numerator larger
		{
			temp = tnum; tnum = tden; tden = temp;
		} // swap them
		tnum = tnum - tden; // subtract them
	}
	gcd = tden; // this is greatest common divisor
	num = num / gcd; // divide both num and den by gcd
	den = den / gcd; // to reduce frac to lowest terms
}

fraction fraction::lowterms(fraction f) const // change ourself to lowest terms
{
	f.lowterms();
	return f;
}

bool fraction::operator == (fraction f2) const
{
	fraction f1(num, den);
	f1.lowterms();
	f2.lowterms();
	if((f1.num==f2.num)&&(f1.den==f2.den))
		return true;
	else
		return false;
}
bool fraction::operator != (fraction f2) const
{
	fraction f1(num, den);
	f1.lowterms();
	f2.lowterms();
	if((f1.num==f2.num)&&(f1.den==f2.den))
		return false;
	else
		return true;
}
////////////////////////////////////////////////////////////////////

int main(){
	fraction f1(4, 15), f2(3, 7), f3;
	cout << "fraction 1: "; f1.showFraction(); cout << endl;
	cout << "fraction 2: "; f2.showFraction(); cout << endl;
	cout << "f1 + f2 = "; f3 = f1+f2; f3.showFraction(); cout << endl;
	cout << "f1 - f2 = "; f3 = f1-f2; f3.showFraction(); cout << endl;
	cout << "f1 * f2 = "; f3 = f1*f2; f3.showFraction(); cout << endl;
	cout << "f1 / f2 = "; f3 = f1/f2; f3.showFraction(); cout << endl;
	fraction f4(0, 1);
	if(f(0,1)==f4) 
		cout << "Equal\n";
	else 
		cout << "Not equal\n" ;
	system("pause");
	return 0;
}