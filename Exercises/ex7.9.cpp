#include <iostream>
#include <string>
using namespace std;
const int MAX = 80;
////////////////////////////////////////////////////////////////
class Queue
	{
	private:
		int data[MAX];              // data: array of integers
		int begin;                   // begin of the queue
		int end;					   // end of queue
		int len;					   // length of queue
	public:
		Queue(): begin(0),end(0), len(0)  //constructor
			{}
		void put(int var);        //put number on queue
		int get();                //get number off queue       
	};
	void Queue::put(int var){
		if(len<MAX){
			data[end++] = var;		// put the new value at the end of queue
			len++;
			if(end == MAX)			// if reach end the of the array, move to start
				end = 0;
		}
		else
			cout << "\nQueue is full! \n";						// add lenght of queue
	}
	int Queue::get(){
		int val;
		if(len > 0){
			val = data[begin++];	// get the value at begin
			len--;
			if(begin == MAX)
				begin = 0;
			return val;
		}
		else{
			cout << "\nQueue is empty! \n";
		}
	}
////////////////////////////////////////////////////////////////
int main()
   {
    Queue q1;
	for(int i = 0; i<85; i++){
		q1.put(i);
		cout << q1.get() << endl;
	}
	for(int i = 0; i<45; i++){
		q1.put(i);
	}
	for(int i = 0; i<45; i++){
		cout << q1.get() << endl;
	}	

	system("pause");
	return 0;
   }