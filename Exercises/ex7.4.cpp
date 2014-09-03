#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////
// function declaration 
int maxint(int intArray[], int len);


void main(){
	int v[80];
	int ind=0;
	char ch;	
	cout << "\nEnter an interger: \n";
	do{		
		cin >> v[ind++];		
		cout << "\nEnter another interger? (y/n)";
		cin >> ch;
	}while(ch != 'n' && ind<80);

	int maxInd;
	maxInd = maxint(v, ind);
	cout << v[maxInd] << " indiced at " 
		 << maxInd <<" is the maximum value of the array" << endl;

	system("pause");
}

///////////////////////////////////////////////////////////////
// function maxint: find the index of maximum valued element
int maxint(int a[], int len){
	int maxInd = 0;
	int maxVal = a[0];
	for(int j = 1; j < len; j++){
		if(a[j] > maxVal){
			maxInd = j; 
			maxVal = a[j];
		}
	}
	return maxInd;
}
///////////////////////////////////////////////////////////////