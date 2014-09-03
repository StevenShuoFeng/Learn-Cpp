// excercise 6.2
// Toll Booth

#include <iostream>
#include <conio.h>
using namespace std;

const char ESC = 27;
const double TOLL = 0.5;

//////////////////////////////////////////////////
class tollBooth
{
	unsigned int nCar;
	double money;
public:
	tollBooth() : nCar(0), money(0.0)
	{}
	void payingCar()
	{
		nCar ++;
		money += TOLL;
	}
	void nopayCar()
	{
		nCar ++;
	}
	void display() const
	{
		cout << "Total car: " << nCar << endl;
		cout << "Total money: " << money << endl;
	}
};

// ---------------------------------

///////////////////////////////////////////////////

int main()
{
	tollBooth booth;
	char button;

	do
	{
		cout << endl << "Please select to pay: " << "Pay(p), No Pay(n), Exit (ESC)" << endl;
		button = _getche();
		switch (button)
		{
		case 'p': booth.payingCar(); break;
		case 'n': booth.nopayCar(); break;
		case ESC: booth.display(); break;
		default: cout << endl << "Invalid button"; break;
		}
	}
	while (button != ESC);

	system("pause");
	return 0;
}