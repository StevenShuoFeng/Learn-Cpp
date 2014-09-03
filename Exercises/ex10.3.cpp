//
//  ex10.3.cpp
//  Learn C++
//
//  Created by Shuo Feng on 9/3/14.
//  Copyright (c) 2014 Shuo Feng. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    void bsort(char**, int);       //prototype
    const int DAYS = 7;            //array size
    //test array
    char* arr[DAYS] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    for(int j=0; j<DAYS; j++)       //print out sorted array
        cout << arr[j] << " ";
    
    
    bsort(arr, DAYS);               //sort the array
    cout << "\nAfter sort:\n";
    for(int j=0; j<DAYS; j++)       //print out sorted array
        cout << arr[j] << " ";
    
    cout << endl;
    return 0;
}
//--------------------------------------------------------------
void bsort(char** ptr, int n)
{
    void order(char**, char**);      //prototype
    int j, k;                    //indexes to array
    
    for(j=0; j<n-1; j++)         //outer loop
        for(k=j+1; k<n; k++)      //inner loop starts at outer
            order(ptr+j, ptr+k);         //order the pointer contents
}
//--------------------------------------------------------------
void order(char** ptrTostrPtr1, char** ptrTostrPtr2)  //orders two numbers
{
    if(**ptrTostrPtr1 > **ptrTostrPtr2)          //if 1st larger than 2nd,
    {
        char* tempStr = *ptrTostrPtr1;        //swap them
        *ptrTostrPtr1 = *ptrTostrPtr2;
        *ptrTostrPtr2 = tempStr;
    }
}