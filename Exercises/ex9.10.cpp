//empmult.cpp
//multiple inheritance with employees and degrees
#include <iostream>
using namespace std;
const int LEN = 80;           //maximum length of names
////////////////////////////////////////////////////////////////
class student                 //educational background
{
private:
	char school[LEN];       //name of school or university
	char degree[LEN];       //highest degree earned
public:
	void getedu()
	{
		cout << "   Enter name of school or university: ";
		cin >> school;
		cout << "   Enter highest degree earned \n";
		cout << "   (Highschool, Bachelor's, Master's, PhD): ";
		cin >> degree;
	}
	void putedu() const
	{
		cout << "\n   School or university: " << school;
		cout << "\n   Highest degree earned: " << degree;
	}
};
////////////////////////////////////////////////////////////////
class employee
{
private:
	char name[LEN];         //employee name
	unsigned long number;   //employee number
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
////////////////////////////////////////////////////////////////
class manager : private employee, private student  //management
{
private:
	char title[LEN];        //"vice-president" etc.
	double dues;            //golf club dues
public:
	void getdata()
	{
		employee::getdata();
		cout << "   Enter title: ";          cin >> title;
		cout << "   Enter golf club dues: "; cin >> dues;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n   Title: " << title;
		cout << "\n   Golf club dues: " << dues;
		student::putedu();
	}
};
////////////////////////////////////////////////////////////////
class executive : private manager{
private:
	double yearBonus;
	unsigned int numStock;
public:
	void getdata(){
		manager::getdata();
		cout << "   Enter size of the employee��s yearly bonus: "; cin >> yearBonus;
		cout << "   Enter number of shares of company stock held: "; cin >> numStock;
	}
	void putdata() const{
		manager::putdata();
		cout << "\n   Size of the employee��s yearly bonus : " << yearBonus;
		cout << "\n   Number of shares of company stock held " << numStock;
	}
};
////////////////////////////////////////////////////////////////
class scientist : private employee, private student  //scientist
{
private:
	int pubs;     //number of publications
public:
	void getdata()
	{
		employee::getdata();
		cout << "   Enter number of pubs: "; cin >> pubs;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n   Number of publications: " << pubs;
		student::putedu();
	}
};
////////////////////////////////////////////////////////////////
class laborer : public employee             //laborer
{
};
////////////////////////////////////////////////////////////////
int main()
{
	executive e1;
	e1.getdata();
	e1.putdata();
	system("pause");
}

