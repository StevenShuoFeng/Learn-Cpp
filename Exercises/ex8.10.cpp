#include <iostream>
#include <cmath>
using namespace std;
const double PI = atan(1) * 4;

class Polar{
private: 
	double radius;
	double angle;
public:
	Polar() : radius(0), angle(0)
	{}
	Polar(double r, double a) : radius(r), angle(a)
	{}
	void display() const{
		cout << "Radius=" << radius << " Angle=" << angle/PI*180 << "Deg";
	}
	Polar operator + (Polar p2) const;
};
Polar Polar::operator + (Polar p2) const{
	double x1, x2, y1, y2, x, y;
	x1 = radius * cos(angle);
	y1 = radius * sin(angle);
	x2 = p2.radius * cos(p2.angle);
	y2 = p2.radius * sin(p2.angle);
	x = x1 + x2; y = y1 + y2;
	return Polar(sqrt(x*x + y*y), atan(y/x));
}

void main(){
	Polar p1(10, PI * 3 / 2), p2(17.32, 0), p3;
	
	p3 = p1 + p2;
	p3.display(); cout << endl;
	system("pause");
}
