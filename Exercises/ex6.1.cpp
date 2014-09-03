#include <iostream>
using namespace std;

//////////////////////////////////////////////
class Int		// class Int
{
	int number;
public:
	Int() : number(0)
	{}
	Int(int i) : number(i)
	{}
	void display();
	void addInt(Int int1, Int int2);
};

void Int::display()
{
	cout << number;
}
void Int::addInt(Int int1, Int int2)
{
	number = int1.number + int2.number;
}

//////////////////////////////////////////////
int main()
{
	Int i1(7), i2(15);
	Int i3;
	i3.addInt(i1, i2);
	i1.display(); cout << " + "; i2.display(); 
	cout << " = "; i3.display(); cout << endl;
	system("pause");
	return 0;
}