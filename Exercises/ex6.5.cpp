#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
class date{
	int month;
	int day;
	int year;
public:
	void getdate(){
		cout << "\nEnter date in format of mm/dd/yy: ";
		char sl;
		cin >> month >> sl >> day >> sl >> year;
	}
	void putdate() const{
		cout << "\nDate is ";
		if (month < 10)
			cout << '0' << month << "/";
		else
			cout << month <<"/";
		if (day < 10)
			cout << '0' << day << "/";
		else
			cout << day << "/";
		if (year < 10)
			cout << '0' << year << "/";
		else
			cout << year << "/";
	}
};
////////////////////////////////////////////////////////////

void main(){
	date d1; 
	d1.getdate();
	d1.putdate();
	system("pause");
}
