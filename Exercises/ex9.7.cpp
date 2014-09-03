// counten2.cpp
// constructors in derived class
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter
   {
   protected:                            //NOTE: not private
      unsigned int count;                //count
   public:
      Counter() : count(0)               //constructor, no args
         {  }
      Counter(int c) : count(c)          //constructor, one arg
         {  }
      unsigned int get_count() const     //return count
         { return count; }
      Counter operator ++ ()             //incr count (prefix)
         { return Counter(++count); }
   };
////////////////////////////////////////////////////////////////
class CountDn : public Counter
   {
   public:
      CountDn() : Counter()              //constructor, no args
         { }
      CountDn(int c) : Counter(c)        //constructor, 1 arg
         { }
      CountDn operator -- ()             //decr count (prefix)
         { return CountDn(--count); }
   };
////////////////////////////////////////////////////////////////
class Countpp : public CountDn{
public:
	Countpp(): CountDn()
	{}
	Countpp(int c): CountDn(c)
	{} 
	Countpp operator ++ (int)
	{return Countpp(count ++); }
	Countpp operator -- (int)
	{return Countpp(count --); }

};

////////////////////////////////////////////////////////////////
int main()
   {
   CountDn c1(10);                           //class CountDn
   CountDn c2;

   cout << "\nc1=" << c1.get_count();
   ++c1;
   cout << "\nPrefix, after operator c1=" << c1.get_count();    //display

   cout << "\nc1=" << c1.get_count();
   c1++;
   cout << "\nPrefix, after operator c1=" << c1.get_count();    //display

   system("pause");

   }
