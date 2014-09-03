//  ex10.2.cpp
//  Learn C++
//
//  Created by Shuo Feng on 9/3/14.
//  Copyright (c) 2014 Shuo Feng. All rights reserved.
//

#include <iostream>
#include <cstring>       //for strcpy(), etc
#include <ctype.h>       // for toupper()

using namespace std;
////////////////////////////////////////////////////////////////
class String             //user-defined string type
{
private:
    char* str;                    //pointer to string
public:
    String(char* s)               //constructor, one arg
    {
        size_t length = strlen(s);    //length of string argument
        str = new char[length+1];  //get memory
        strcpy(str, s);            //copy argument to it
    }
    void upit()                     // modify string to upper case
    {
        int k = 0;
        while (*(str+k)) {
            *(str+k) = (char) toupper(*(str+k));
            k++;
        }
    }
    ~String()                     //destructor
    {
        cout << "Deleting str\n";
        delete[] str;              //release memory
    }
    void display()                //display the String
    {
        cout << str << endl;
    }
};
////////////////////////////////////////////////////////////////
int main()
{                                //uses 1-arg constructor
    String s1 = "Who knows nothing doubts nothing.";
    cout << "s1=";                   //display string
    s1.display();
    
    s1.upit();
    
    cout << "Upper case: ";                   //display string
    s1.display();
    return 0;
}