#include <iostream>
#include <string>
using namespace std;
const int MAXEMPLOYEE = 100;

//////////////////////////
// class employee
class Employee{
	string name;
	long num;
public:
	void getdata();
	void putdata();
};
void Employee::getdata(){
	cout << "\nType employee name: ";
	//getline(cin, name);
	cin >> name;
	cout << "Enter employee number: ";
	cin >> num;
}
void Employee::putdata(){
	cout << "\nEmployee name: " << name;
	cout << "\nEmployee number: " << num << endl;
}
//////////////////////////

void main(){

	Employee arrayEmployee[MAXEMPLOYEE];
	int n = 0; // number of employees 
	char ch;
	do{
		cout << "\nEnter information for employee number " << n+1;
		arrayEmployee[n].getdata();
		n ++ ;
		cout << "\nEnter another (y/n)?";
		cin >> ch;
	}while(ch!= 'n');

	for(int i = 0; i<n; i++){
		cout << "\nEmployee number " << i+1 ;
		arrayEmployee[i].putdata();
	}
	system("pause");
}
