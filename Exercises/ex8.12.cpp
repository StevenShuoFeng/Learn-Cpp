#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
using namespace std;
const long double MAXVALUE = 9999999999999990;

long double mstold(char a[]);
class bMoney
{
private:
	long double money;
public:
	bMoney(){};
	bMoney(char s[]){ money = mstold(s); };
	void madd(bMoney m1, bMoney m2);
	void getmoney();
	void putmoney() const;
	void setmoney(long double m) { money = m; }
	long double sendmoney() const { return money; }
	bMoney operator + (bMoney b2) const;
	bMoney operator - (bMoney b2) const;
	bMoney operator * (long double w) const;
	long double operator / (bMoney b2) const;
	bMoney operator / (long double w) const;

};
void bMoney::getmoney(){
	char a[27];
	cout << "\nPlease enter money amount:";
	cin >> setw(27) >> a;
	money = mstold(a);
}
void bMoney::putmoney() const{
	string s;
	if (money > MAXVALUE)
		cout << "\n Value too large! \n";
	else{
		// split integer part and decimal
		long long integer = (long long)money;	// integer part
		int dec = round((money - (long double)integer) * 100); // 2 decimal digits	
		// convert integer to string
		stringstream s1;
		s1 << integer;
		string sinteger = s1.str();
		// insert comma
		int nComma = (sinteger.length() - 1) / 3;
		for (int j = 1; j <= nComma; j++)
			sinteger.insert(sinteger.length() - 4 * j + 1, ",");
		// convert decimal to string
		stringstream s2;
		s2 << dec;
		string sdec;
		if (dec<10)
			sdec = "0" + s2.str();
		else
			sdec = s2.str();
		s = '$' + sinteger + '.' + sdec; // combine
	}
	cout << "\nYour money is: " << s << endl;
}
void bMoney::madd(bMoney m1, bMoney m2){
	money = m1.money + m2.money;
}
bMoney bMoney::operator + (bMoney b2) const{
	bMoney b;
	b.setmoney(sendmoney() + b2.sendmoney());
	return b;
}
bMoney bMoney::operator - (bMoney b2) const{
	bMoney b;
	b.setmoney(sendmoney() - b2.sendmoney());
	return b;
}
bMoney bMoney::operator * (long double w) const{
	bMoney b;
	b.setmoney(sendmoney() * w);
	return b;
}
long double bMoney::operator / (bMoney b2) const{
	return (sendmoney() / b2.sendmoney());
}
bMoney bMoney::operator / (long double w) const{
	bMoney b;
	b.setmoney(sendmoney() / w);
	return b;
}
long double mstold(char a[]){
	char b[18];
	int ind = 0;
	for (unsigned int i = 0; i<strlen(a); i++){
		if ((a[i] >= '0'&&a[i] <= '9') || a[i] == '.')
			b[ind++] = a[i];
	}
	b[ind] = '\0';
	return stold(b);
}

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
		pence = round(m * 20 * 12);
	}
	sterling(bMoney b)
	{
		long double m = b.sendmoney()/50;
		pounds = (long)m; m -= pounds;
		shillings = (int)(m / 0.05); m -= shillings*0.05;
		pence = round(m * 20 * 12);
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
	operator double() const{
		double d;
		d = pounds + shillings*0.05f + pence * 0.05f / 12;
		return d;
	}
	sterling operator + (sterling s2) const;
	sterling operator - (sterling s2) const;
	sterling operator * (sterling s2) const;
	sterling operator / (sterling s2) const;
	operator bMoney () const;
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
sterling::operator bMoney() const{
	bMoney b;
	double d;
	d = pounds + shillings*0.05f + pence * 0.05f / 12;
	b.setmoney(d*50);
	return b;
}

void main(){
	sterling s;
	bMoney b;

	b.setmoney(125); s = b;
	cout << "\nPound: "; s.putSterling();
	b = s;
	cout << "\nEquivalent dollar: "; b.putmoney();
	s = b;
	cout << "\nBack to pound: "; s.putSterling();
	system("pause");
}