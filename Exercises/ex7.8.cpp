#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
const int LIMIT = 20;

//////////////////////////////////////////////////
class safearay
{
private:
	int data[LIMIT];
public:
	safearay()
	{ for(int i=0; i<LIMIT; i++)
		 data[i] = 0;
	}
	safearay(int a[])
	{ for(int i=0; i<LIMIT; i++)
		 data[i] = a[i];
	}
	void putel(int ind, int val);
	int getel(int ind);
};
void safearay::putel(int ind, int val){
	if(ind>=0 && ind<LIMIT-1)
		data[ind]  = val;
	else
		cout << "Warning: Index out of arrange!";
}
int safearay::getel(int ind){
	if(ind>=0 && ind<LIMIT-1)
		return data[ind];
	else
		cout << "Warning: Index out of arrange!";
}
//////////////////////////////////////////////////

void main(){
	safearay sa1;
	int temp = 12345;
	sa1.putel(7,temp);

	for(int i = 0; i < LIMIT-1; i++)
	cout << sa1.getel(i) << endl;
	system("pause");
}