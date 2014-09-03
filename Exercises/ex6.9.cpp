// excercise 6.9
#include <iostream>
using namespace std;

class fraction{
	int num; // numerator
	int den; // denominator

public:
	void getFract();
	void showFract() const;
	void addFract(fraction f1, fraction f2);
};
void fraction::getFract(){
	char trash;
	cin >> num >> trash >> den;
}
void fraction::showFract() const{
	cout << num << "/" << den;
}
void fraction::addFract(fraction f1, fraction f2){
	num = f1.num*f2.den + f1.den*f2.num;
	den = f1.den*f2.den;
}

int main(){
	fraction f1,f2,f3;
	cout << "Enter a fraction" << endl;
	f1.getFract();
	cout << "You entered: ";  f1.showFract(); cout << endl;
	cout << "Enter a fraction" << endl;
	f2.getFract();
	cout << "You entered: ";  f2.showFract(); cout << endl;

	f3.addFract(f1, f2);
	cout << "The sum is: "; f3.showFract(); cout << endl;

	system("pause");
}