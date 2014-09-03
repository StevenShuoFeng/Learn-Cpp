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
		bMoney(char s[]){money = mstold(s);};
		void madd(bMoney m1, bMoney m2);
		void getmoney();
		void putmoney();
	};
void bMoney::getmoney(){
	char a[27];
	cout << "\nPlease enter money amount:";
	cin >> setw(27) >> a;	
	money = mstold(a);
}
void bMoney::putmoney(){
		string s;
	if( money > MAXVALUE)
		cout << "\n Value too large! \n";
	else{
		// split integer part and decimal
		long long integer = (long long)money;	// integer part
		int dec = double((money - (long double)integer) * 100;) // 2 decimal digits	
		// convert integer to string
		stringstream s1;		
		s1 << integer;
		string sinteger = s1.str();	
			// insert comma
		int nComma = (sinteger.length()-1)/3; 
		for(int j = 1; j <= nComma; j++)
			sinteger.insert(sinteger.length()-4*j+1, ",");
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
long double mstold(char a[]){
	char b[18];
	int ind = 0;
	for(unsigned int i = 0; i<strlen(a); i++){
		if( (a[i]>='0'&&a[i]<='9') || a[i]=='.')
			b[ind++] = a[i];
	}
	b[ind] = '\0';
	return stold(b);
}

void main(){
	bMoney b1,b3;
	b1.getmoney();
	bMoney b2("$411.22");
	b3.madd(b1, b2);

	cout << "First input:";
	b1.putmoney();
	cout << "Second input:";
	b2.putmoney();
	cout << "Sum: ";
	b3.putmoney();
	system("pause");
}