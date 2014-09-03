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
	void fadd(fraction f1, fraction f2); 
	void fsub(fraction f1, fraction f2);
	void fmul(fraction f1, fraction f2);
	void fdiv(fraction f1, fraction f2);
	void lowterms(); // change the fraction to lowest terms
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
void fraction::fadd(fraction f1, fraction f2){ // f1 + f2
	num = f1.num*f2.den + f1.den*f2.num;
	den = f1.den * f2.den;
	lowterms();
}
void fraction::fsub(fraction f1, fraction f2){ // f1 - f2
	num = f1.num*f2.den - f1.den*f2.num;
	den = f1.den * f2.den;
	lowterms();
}
void fraction::fmul(fraction f1, fraction f2){ // f1 * f2
	num = f1.num * f2.num;
	den = f1.den * f2.den;
	lowterms();
}
void fraction::fdiv(fraction f1, fraction f2){ // f1 / f2
	num = f1.num * f2.den;
	den = f1.den * f2.num;
	lowterms();
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
////////////////////////////////////////////////////////////////////

int main(){
	fraction f1(4, 15), f2(3, 7), f3;
	cout << "fraction 1: "; f1.showFraction(); cout << endl;
	cout << "fraction 2: "; f2.showFraction(); cout << endl;
	cout << "f1 + f2 = "; f3.fadd(f1, f2); f3.showFraction(); cout << endl;
	cout << "f1 - f2 = "; f3.fsub(f1, f2); f3.showFraction(); cout << endl;
	cout << "f1 * f2 = "; f3.fmul(f1, f2); f3.showFraction(); cout << endl;
	cout << "f1 / f2 = "; f3.fdiv(f1, f2); f3.showFraction(); cout << endl;
	system("pause");
	return 0;
}