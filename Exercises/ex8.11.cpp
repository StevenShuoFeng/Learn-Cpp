#include <iostream>
#include <math.h>
using namespace std;

class sterling
{
private:
	long pounds;
	int shillings;
	int pence;
public:
	sterling() : pounds(0), shillings(0), pence(0)
	{}
	sterling(long p, int s, int pen) : pounds(p), shillings(s), pence(pen)
	{}
	sterling(double m)
	{
		pounds = (long)m; m -= pounds;
		shillings = (int)(m / 0.05); m -= shillings*0.05;
		pence = floor(m * 20 * 12);
	}
	void putSterling() const{
		cout << "$" << pounds << "." << shillings << "." << pence;
	}
	void getSterling(){
		cout << "Enter value in pound, shilling and penny: \n";
		cout << "Pound: "; cin >> pounds;
		cout << "Shilling: "; cin >> shillings;
		cout << "Penny: "; cin >> pence;
	}
	operator double(){
		double d;
		d = pounds + shillings*0.05f + pence * 0.05f / 12;
		return d;
	}
	sterling operator + (sterling s2) const;
	sterling operator - (sterling s2) const;
	sterling operator * (sterling s2) const;
	sterling operator / (sterling s2) const;
};
sterling sterling::operator + (sterling s2) const
{
	return sterling(double(sterling(pounds, shillings, pence)) + double(s2));
}
sterling sterling::operator - (sterling s2) const
{
	return sterling(double(sterling(pounds, shillings, pence)) - double(s2));
}
sterling sterling::operator * (sterling s2) const
{
	return sterling(double(sterling(pounds, shillings, pence)) * double(s2));
}
sterling sterling::operator / (sterling s2) const
{
	return sterling(double(sterling(pounds, shillings, pence)) / double(s2));
}

void main(){
	double d1 = 5.13, d2 = 2.35;
	sterling s1(d1);
	sterling s2(d2), s3;
	s3 = s1 + s2;
	cout << "s3: ";
	s3.putSterling(); cout << endl;
	cout << double(s3) << endl;
	double d3 = d1+d2;
	cout << d3 << endl;
	system("pause");
}