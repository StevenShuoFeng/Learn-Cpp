#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 10;

/////////////////////////////////////////////////////////////////////
class matrix
	{
		int data[MAX][MAX];
		int maxr, maxc;			// maximum size of row and column
	public:
		matrix()					// matrix size set to MAX-by-MAX
		{
			maxr = MAX; 
			maxc = MAX;
			for(int i = 0; i < MAX; i++)
				for(int j = 0; j < MAX; j++)
					data[i][j] = 0; // initialize to 0
		};
		matrix(int row, int col) // user defined matrix size
		{
			if(row<MAX && col<MAX && row>0 && col>0) // max size is 10
			{
				maxr = row; 
				maxc = col;
				for(int i = 0; i < maxr; i++)
					for(int j = 0; j < maxc; j++)
						data[i][j] = 0; // initialize to 0
			}
			else
				cout << "\nCannot initialize matrix larger than 10-by-10.\n";
		};
		void putel(int row, int col, int val);
		int getel(int row, int col);
};
void matrix::putel(int r, int c, int v){
	if(r>=0 && r<maxr && c>=0 && c<maxc)
		data[r][c] = v;
	else
		cout << "\nCannot put value. Index out of range! \n";
}
int matrix::getel(int r, int c){
	if(r>=0 && r<maxr && c>=0 && c<maxc)
		return data[r][c];
	else
		cout << "\nCannot get value. Index out of range! \n";
}
/////////////////////////////////////////////////////////////////////

void main(){
	matrix m1(3, 4);           // define a matrix object
	int temp = 12345;          // define an int value
	m1.putel(1, 2, temp);      // insert value of temp into matrix at 7,4
	temp = m1.getel(7, 4);     // obtain value from matrix at 7,4
	cout << temp << endl;

	cout << "\nMatrix m1: \n";
	for(int i = 0; i < 3; i++)
	{
				for(int j = 0; j < 4; j++)
					cout << setw(8) <<m1.getel(i,j); 
				cout << endl;
	}

	matrix m2(5,15);
	system("pause");
}