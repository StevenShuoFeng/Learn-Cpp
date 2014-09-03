#include <iostream>
#include <cstring>                //for strcpy(), etc.
using namespace std;
////////////////////////////////////////////////////////////////
class String                      //base class
{
protected:                     //Note: can't be private
	enum { SZ = 80 };           //size of all String objects
	char str[SZ];               //holds a C-string
public:
	String()                    //constructor 0, no args
	{
		str[0] = '\0';
	}
	String(char s[])          //constructor 1, one arg
	{
		strcpy(str, s);
	}      //  convert string to String
	void display() const        //display the String
	{
		cout << str;
	}
	operator char*()            //conversion function
	{
		return str;
	}          //convert String to C-string
};
////////////////////////////////////////////////////////////////
class Pstring : public String     //derived class 
{
public:
	Pstring(char s[]);        //constructor
};
//--------------------------------------------------------------
Pstring::Pstring(char s[])      //constructor for Pstring
{
	if (strlen(s) > SZ - 1)           //if too long,
	{
		for (int j = 0; j<SZ - 1; j++)   //copy the first SZ-1
			str[j] = s[j];           //characters "by hand"
		str[SZ - 1] = '\0';              //add the null character
	}
	else                           //not too long,
	{
		strcpy(str, s);
	};                  //so construct normally
}
////////////////////////////////////////////////////////////////
class Pstring2 : public Pstring{
public:
	Pstring2(char s[]) : Pstring(s)
	{}
	void left(Pstring2 s2, int copyLen){
		for (int i = 0; i < copyLen; i++)
			str[i] = s2.str[i];
		str[copyLen] = '\0';
	}
	void right(Pstring2 s2, int copyLen){
		int strLen = strlen(s2.str);
		for (int i = 0; i < copyLen; i++)
			str[copyLen - i - 1] = s2.str[strLen - i - 1];		
		str[copyLen] = '\0';
	}
	void mid(Pstring2 s2, int startPnt, int copyLen){
		for (int i = 0; i < copyLen; i++)
			str[i] = s2.str[startPnt+i-1];
		str[copyLen] = '\0';
	}

};

////////////////////////////////////////////////////////////////

void main(){
	Pstring2 s1 = "This-is-an-old-string.";
	Pstring2 s2("hi, 123"), s3("yo, 456"), s4("YamiYummy");

	cout << "\ns1 = "; s1.display();
	cout << "\ns2 = "; s2.display();

	int lenLeft = 4;
	cout << "\nCopy the left " << lenLeft << " letters of s1:";
	s2.left(s1, lenLeft);
	cout << "\ns2 = "; s2.display();

	int lenRight = 5;
	cout << "\ns3 = "; s3.display();
	cout << "\nCopy the right " << lenRight << " letters of s1:";
	s3.right(s1, lenRight);
	cout << "\ns3 = "; s3.display();

	int LenMid = 6, strtPnt = 9;
	cout << "\ns4 = "; s4.display();
	cout << "\nCopy the middle " << LenMid << " letters, starting from letter #" << strtPnt;
	s4.mid(s1, strtPnt, LenMid);
	cout << "\ns4 = "; s4.display();
	cout << endl;
	system("pause");
}