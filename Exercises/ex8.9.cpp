
#include <iostream>
using namespace std;
#include <process.h>           //for exit()
const int LIMIT = 100;         //array size
////////////////////////////////////////////////////////////////
class safearay
{
private:
	int arr[LIMIT];
	int upper, lower;
public:
	safearay() : lower(0), upper(LIMIT - 1)
	{}
	safearay(int l, int u) : lower(l), upper(u)
	{
		if ( u-l < 0 || u-l >= LIMIT)
		{
			cout << "\nCannot create array. Index out of bounds.\n"; 
			system("pause");  exit(1);
		}
		arr[u - l +1];
	}

	int& operator [](int n)  //note: return by reference
	{
		if (n< lower || n > upper)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		return arr[n-lower];
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	int l = 550, u = 600;
	safearay sa1(l, u);

	for (int j = l; j<= u; j++)  //insert elements
		sa1[j] = j * 10;           //*left* side of equal sign

	for (int j = l; j<= u; j++)      //display elements
	{
		int temp = sa1[j];       //*right* side of equal sign
		cout << "Element " << j << " is " << temp << endl;
	}
	system("pause");
	return 0;
}