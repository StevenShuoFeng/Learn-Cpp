// excercise 6.8
#include <iostream>
#include <iomanip>
using namespace std;

class countObj{
	static int N;
	int num;
public:
	countObj()
	{
		N++; num = N;
	}
	void reportCount() const
	{
		cout << setw(20) << "I am object number " << setw(5) << num << endl;
	}
};
int countObj::N = 0;

int main(){
	countObj c1;
	c1.reportCount();
	countObj c2;
	c2.reportCount();
	countObj c3;
	c3.reportCount();
	system("pause");
}