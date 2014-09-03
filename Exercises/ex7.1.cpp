#include <iostream>
#include <string>
using namespace std;

void reversit(char m[]);

void main(){
	const int MAX = 50;
	char charray[MAX];
	cout << "\n Please enter a word: ";
	cin.get(charray, MAX);
	reversit(charray);
	cout << "\n The reverse word is: "
		 << charray << endl;
	system("pause");
}

// function reversit 
// reverse the order of characters of an array
void reversit(char s[]){
	int len = strlen(s); 
	char tp;
	for(int j=0; j<len/2; j++){
		tp = s[j];
		s[j] = s[len-1-j];
		s[len-1-j] = tp;
	}
}