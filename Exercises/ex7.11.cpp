#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
const long double MAXVALUE = 9999999999999990;

string ldtoms(long double dollar);

void main(){
	long double ld = 2235153129.23;
	stringstream s;
	s << ld;
	cout << s.str() << endl;

	cout << ldtoms(ld) << endl;
	system("pause");
}

string ldtoms(long double dollar){
	string s;
	if( dollar > MAXVALUE)
		cout << "\n Value too large! \n";
	else{
		// split integer part and decimal
		long long integer = (long long)dollar;	// integer part
		int dec = (dollar - (long double)integer)*100; // 2 decimal digits	
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
		string sdec = s2.str();
		s = '$' + sinteger + '.' + sdec; // combine
	}
	return s;
}