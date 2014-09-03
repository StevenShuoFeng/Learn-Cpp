
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

long double mstold(char a[]){
	char b[18] = "";
	int ind = 0;
	for(unsigned int i = 0; i<strlen(a); i++){
		if( (a[i]>='0'&&a[i]<='9') || a[i]=='.')
			b[ind++] += a[i];
	}
	b[ind] = '\0';
	return stold(b);
}

void main(){
	char a[] = "$12,219,291.04";
	long double b;
	cout << "Old string: " << a << endl;
	b = mstold(a);
	cout << "New string: " << setprecision(19) << b << endl;
	system("pause");
}

