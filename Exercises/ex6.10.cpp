//excercise 6.10

#include <iostream>
#include <conio.h>
using namespace std;

//////////////////////////////////////////////////////////
class angle{
	int deg;
	double min;
	char dir;
public:
	angle() : deg(0), min(0), dir('0')
	{}
	angle(int d, double m, char dr) : deg(d), min(m), dir(dr)
	{}
	void getAngle(){
		cout << "Enter degree: ";
		cin >> deg;
		cout << "Enter minute: ";
		cin >> min;
		do{
			cout << "Enter direction (S,N or W,E): ";
			dir = _getche();
			cout << endl;
		} while (dir != 'S' && dir != 'N' && dir != 'W' && dir != 'E');
	}
	void displayAngle() const{
		cout << deg << " deg " << min << " min " << dir << endl;
	}
};
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
class ship{ 
	static int totalShip; 
	int shipNum; // ship number
	angle latit; // latitude
	angle longit; // longitude
public:
	ship()
	{
		totalShip++; shipNum = totalShip;
		getPosition();
	}
	void getPosition(){
		cout << "Provide latitude for ship # " << shipNum << endl;
		latit.getAngle();
		cout << "Provide longitude for ship # " << shipNum << endl;
		longit.getAngle();
	}
	void showPosition() const{
		cout << "The position of ship # " << shipNum << " is :" << endl;
		cout << "---------" << endl;
		cout << "Latitude : "; latit.displayAngle();
		cout << "Longitude : "; longit.displayAngle();
		cout << "---------" << endl;
	}
};
int ship::totalShip = 0;
//////////////////////////////////////////////////////////

int main(){
	ship ship1;
	ship ship2;
	ship1.showPosition();
	ship2.showPosition();
	system("pause");
	return 0;
}