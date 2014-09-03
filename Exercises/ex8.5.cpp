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
	void display() const;
	time operator ++();
	time operator --();
	time operator ++(int);
	time operator --(int);
	time operator + (time t2) const;
	time operator - (time t2) const;
	time operator * (float c) const;

};
// ------------------------------------
void time::display() const
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
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
time time::operator++()
{
	++seconds;
	if(seconds>59)
	{seconds -= 60; minutes++;}
	if(minutes>59)
	{minutes -= 60; hours++;}
	return time(hours, minutes, seconds);
}
time time::operator--()
{
	--seconds;
	if(seconds<0)
	{seconds += 60; minutes--;}
	if(minutes<0)
	{minutes += 60; hours--;}
	return time(hours, minutes, seconds);
}
time time::operator++(int)
{
	int h = hours, m = minutes, s = seconds;
	seconds++;
	if(seconds>59)
	{seconds -= 60; minutes++;}
	if(minutes>59)
	{minutes -= 60; hours++;}
	return time(h, m, s);
}
time time::operator--(int)
{
	int h = hours, m = minutes, s = seconds;
	seconds--;
	if(seconds<0)
	{seconds += 60; minutes--;}
	if(minutes<0)
	{minutes += 60; hours--;}
	return time(h, m, s);
}
time time::operator - (time t2) const
{
	int h, m, s;
	int sec1 = 3600*hours + 60*minutes + seconds;
	int sec2 = 3600*t2.hours + 60*t2.minutes + t2.seconds;
	int Dt = sec1 - sec2;
	h = Dt/3600; Dt -= h*3600;
	m = Dt/60; Dt -= m*60;
	s = Dt;
	return time(h, m, s);
}

time time::operator * (float scale) const
{
	int h, m, s;
	int sec1 = 3600*hours + 60*minutes + seconds;
	int Dt = (int) (sec1 * scale);
	h = Dt/3600; Dt -= h*3600;
	m = Dt/60; Dt -= m*60;
	s = Dt;
	return time(h, m, s);
}
/////////////////////////////////////////////////

int main()
{
	const time t1(1, 10, 35), t2(0, 55, 44);
	time t3, t6;
	time t4(0,1,1);

	// add two times to t3 and t4
	t3 = t1+t2;
	cout << "Time 1: "; t1.display();
	cout << "Time 2: "; t2.display();
	cout << "Time 3 = time 1 + time 2: "; t3.display();
	t4 = t3++;	
	cout << "Time 4 = time3: "; t4.display();
	time t5(2, 29 ,59);
	cout << "Time 5: "; t5.display();
	t6 = t5++;	
	cout << "Time 6 = time 5++: "; t6.display();
	cout << "Time 5: "; t5.display();
	time t7(2, 29 ,59);
	cout << "Time 7: "; t7.display();
	t6 = ++t7;
	cout << "Time 6 = ++time 7: "; t6.display();
	cout << "Time 7: "; t7.display();
	time t8 = t2 - t1;
	cout << "Time 8 = time 2 - time 1: "; t8.display();
	time t9 = t1 - t2;
	cout << "Time 9 = time 1 - time 2: "; t9.display();
	time t10 = t1 * 2.0f;
	cout << "Time 10 = time 1 * 2: "; t10.display();
	system("pause");
	return 0;
}