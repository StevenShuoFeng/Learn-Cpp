// excercise 6.7

#include <iostream>
#include <conio.h>
using namespace std;

const char ESC = 27;
const unsigned char DEGREE = 248;

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
		cout << "Enter degree for the angle: ";
		cin >> deg;
		cout << "Enter minute for the angle: ";
		cin >> min;
		do{ 
			cout << "Enter direction (S,N or W,E): "; 
			dir = getche();
			cout << endl;
		}		
		while ( dir!='S' && dir!='N' && dir!='W' && dir!='E' );
	}
	void displayAngle() const{
		cout << deg << " deg " << min << " min " << dir << endl;
	}
};
//////////////////////////////////////////////////////////

int main(){
	angle a1(43, 15.3, 'E');
	a1.displayAngle();

	char ch;
	do{
		a1.getAngle();
		a1.displayAngle();
		cout << "Press any key to enter another angle, ESC to quit" << endl;
		ch = getch();
	} while (ch != ESC);
}