#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////
class publication{
private:
	string title;
	float price;
public:
	void getdata(){
		cout << "Enter publication title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
	}
	void putdata() const{
		cout << "Publication title: " << title << endl;
		cout << "Price: " << price << endl;
	}
};
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
			cout << month << "/";
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
class publication2: public publication{
private:
	date pubDate;
public:
	void getdata(){
		publication::getdata();
		pubDate.getdate();
	}
	void putdata() const{
		publication::putdata();
		pubDate.putdate();
	}
};

////////////////////////////////////////////////////////////
class book : public publication2{
private:
	int pageCnt;
public:
	void getdata(){
		publication2::getdata();
		cout << "Enter page number: ";
		cin >> pageCnt;
	}
	void putdata() const {
		publication2::putdata();
		cout << "\nPage number: " << pageCnt << endl;
	}
};
////////////////////////////////////////////////////////////
class tape : public publication2{
private:
	float playTime;
public:
	void getdata(){
		publication2::getdata();
		cout << "Enter play time: ";
		cin >> playTime;
	}
	void putdata() const {
		publication2::putdata();
		cout << "\nPlay time: " << playTime << endl;
	}
};
////////////////////////////////////////////////////////////
void main(){
	book b;
	tape t;
	b.getdata();
	t.getdata();
	b.putdata();
	t.putdata();
	system("pause");
}