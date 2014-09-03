
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
class publication                     // base class
{
private:
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nEnter title: "; cin >> title;
		cout << "Enter price: "; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
};
////////////////////////////////////////////////////////////////
class sales{
protected:
	enum { MONTH = 3 };
	float salesAry[MONTH];
public:
	void getdata(){
		for (int i = 0; i < MONTH; i++){
			cout << "Enter sale value for month " << i + 1 << " :"; cin >> salesAry[i];
		}
	}
	void putdata() const{
		for (int i = 0; i < MONTH; i++){
			cout << "\nSale of month " << i + 1 << " is " << salesAry[i] << ".";
		}
	}
};
////////////////////////////////////////////////////////////////
class book : private publication, private sales      // derived class
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter number of pages: "; cin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPages: " << pages;
		sales::putdata();
	}
};
////////////////////////////////////////////////////////////////
class tape : private publication, private sales     // derived class
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter playing time: "; cin >> time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPlaying time: " << time;
		sales::putdata();
	}
};
///////////////////////////////////////////////////////////
class disk : private publication, private sales     // derived class
{
private:
	enum diskType {CD = 0 , DVD = 1};
	diskType dtype;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter disk type: c for CD, d for DVD"; 
		char tmp; cin >> tmp;  if (tmp == 'c') dtype = CD; else dtype = DVD;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nDisk type: ";
		if(dtype == CD) cout << "CD"; else cout << "DVD";
		sales::putdata();
	}
};
void main(){
	disk d;
	d.getdata();
	d.putdata();
	system("pause");
}