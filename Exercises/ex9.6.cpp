#include <iostream>
using namespace std;
#include <process.h>           //for exit()
const int LIMIT = 100;         //array size

////////////////////////////////////////////////////////////////
class safearay
   {
   private:
      int arr[LIMIT];
   public:
      int& operator [](int n)  //note: return by reference
         {
         if( n< 0 || n>=LIMIT )
            { cout << "\nIndex out of bounds"; exit(1); }
         return arr[n];
         }
   };
////////////////////////////////////////////////////////////////
class safearay2: public safearay{
private:
	int lBound, uBound;
public:
	safearay2(int lb, int ub) : lBound(lb), uBound(ub)
	{}
	int& operator [](int n){
		if(n>uBound)
			{cout << "\nIndex out of bounds"; exit(1);};
		return safearay::operator[](n - lBound);
	}
};

////////////////////////////////////////////////////////////////
void main(){
	int lb = 120, ub = 150;

	safearay2 sa1(lb, ub);

	for(int j= lb; j<= ub; j++)  //insert elements
		sa1[j] = j*10;           //*left* side of equal sign

	for(int j= lb; j<= ub; j++)      //display elements
		{
		int temp = sa1[j];       //*right* side of equal sign
		cout << "Element " << j << " is " << temp << endl;
		}
	system("pause");
}