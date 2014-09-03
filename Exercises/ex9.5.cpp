// employ.cpp
// models employee database using inheritance
#include <iostream>
using namespace std;
const int LEN = 80;                //maximum length of names
////////////////////////////////////////////////////////////////
class employee2                     //employee class
{
private:
	char name[LEN];              //employee name
	unsigned long number;        //employee number

	double compensation;
	enum period {hourly, weekly, monthly};
public:
	void getdata()
	{
		cout << "\n   Enter last name: "; cin >> name;
		cout << "   Enter number: ";      cin >> number;
	}
	void putdata() const
	{
		cout << "\n   Name: " << name;
		cout << "\n   Number: " << number;
	}
};