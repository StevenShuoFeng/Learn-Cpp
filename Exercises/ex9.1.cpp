#include <iostream>
#include <string>
using namespace std;

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

class book : public publication{
private:
	int pageCnt;
public:
	void getdata(){
		publication::getdata();
		cout << "Enter page number: ";
		cin >> pageCnt;
	}
	void putdata() const {
		publication::putdata();
		cout << "Page number: " << pageCnt << endl;
	}
};

class tape : public publication{
private:
	float playTime;
public:
void getdata(){
		publication::getdata();
		cout << "Enter play time: ";
		cin >> playTime;
	}
	void putdata() const {
		publication::putdata();
		cout << "Play time: " << playTime << endl;
	}
};

void main(){
	book b;
	tape t;
	b.getdata();
	t.getdata();
	b.putdata();
	t.putdata();
	system("pause");
}