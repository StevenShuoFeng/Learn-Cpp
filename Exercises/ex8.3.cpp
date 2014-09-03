// excercise 6.3

#include <iostream>
using namespace std;

/////////////////////////////////////////////////
class time
{
	int hours, minutes, seconds;
public:
	time() : hours(0), minutes(0), seconds(0)
	{}
	time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
	{}
	void add(time t1, time t2);
	void display() const;
	time operator + (time t2) const;
};
// ------------------------------------
void time::display() const
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
}
void time::add(time t1, time t2)
{
	seconds = 0; minutes = 0; hours = 0;
	seconds = t1.seconds + t2.seconds;
	if (seconds >= 60)
	{
		seconds -= 60;
		minutes++;
	}

	minutes += t1.minutes + t2.minutes;
	if (minutes >= 60)
	{
		minutes -= 60;
		hours++;
	}

	hours += t1.hours + t2.hours;
}
time time::operator + (time t2) const{
	int hrs, min, sec;
	sec = seconds + t2.seconds;
	min = minutes + t2.minutes;
	hrs = hours + t2.hours;
	if(sec>59)
	{sec -= 60; min++;}
	if(min>59)
	{min -= 60; hrs++;}
	return time(hrs, min, sec);
}
/////////////////////////////////////////////////

int main()
{
	const time t1(1, 10, 35), t2(0, 55, 44);
	time t3;
	time t4(0,1,1);

	// add two times to t3 and t4
	t3.add(t1, t2);
	t4.add(t1, t2);
	cout << "Time 1: "; t1.display();
	cout << "Time 2: "; t2.display();
	cout << "Time 3 = time 1 + time 2: "; t3.display();
	cout << "Time 4 = time 1 + time 2: "; t4.display();
	time t5 = t1+t2;
	cout << "Time 5 = time 1 + time 2: "; t5.display();

	system("pause");
	return 0;
}