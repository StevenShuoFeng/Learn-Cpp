#include <iostream>
using namespace std;
#include <process.h>            //for exit()
////////////////////////////////////////////////////////////////
class Stack
{
protected:                   //NOTE: can't be private
	enum { MAX = 30 };         //size of stack array
	int st[MAX];              //stack: array of integers
	int top;                  //index to top of stack
public:
	Stack()                   //constructor
	{
		top = -1;
	}
	void push(int var)        //put number on stack
	{
		st[++top] = var;
	}
	int pop()                 //take number off stack
	{
		return st[top--];
	}
};
////////////////////////////////////////////////////////////////
class Stack2 : public Stack
{
public:
	void push(int var)        //put number on stack
	{
		if (top >= MAX - 1)	     //error if stack full
		{
			cout << "\nError: stack is full"; exit(1);
		}
		Stack::push(var);      //call push() in Stack class
	}
	int pop()                 //take number off stack
	{
		if (top < 0)            //error if stack empty
		{
			cout << "\nError: stack is empty\n"; exit(1);
		}
		return Stack::pop();   //call pop() in Stack class
	}
};
////////////////////////////////////////////////////////////////
struct Pair{
	int x, y;
	Pair(int a, int b) : x(a), y(b)
	{}
};
////////////////////////////////////////////////////////////////
class pairStack : private Stack2{
public :
	void push(Pair p){
		Stack2::push(p.x);
		Stack2::push(p.y);
	}
	Pair pop(){
		int y = Stack2::pop();
		int x = Stack2::pop();
		Pair p(x, y);
		return p;
	}
};
////////////////////////////////////////////////////////////////
void main(){

	pairStack s;
	int x, y;
	for (int i = 0; i < 2; i++){
		cout << "\nEnter a pair of 2 numbers: "; cin >> x >> y;
		Pair p(x, y); s.push(p);
	}
	for (int i = 0; i < 2; i++){
		cout << "The pair number u entered are: \n";
		Pair p = s.pop();
		cout << p.x << "-" << p.y << endl;
	}
	system("pause");
}