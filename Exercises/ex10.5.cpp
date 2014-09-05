//
//  ex10.5.cpp
//  Learn C++
//
//  Created by Shuo Feng on 9/5/14.
//  Copyright (c) 2014 Shuo Feng. All rights reserved.
//

#include <iostream>

void addarrays(float* input1, float* input2, float* output, int len)
{
    for (int k = 0; k < len; k++) {
        *(output+k) = *(input1+k) + *(input2+k);
    }
}

int main(){
    const int arrayLength = 10;
    float array1 [arrayLength] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float array2 [arrayLength] = {1, 1, 2, 2, 3, 3, 2, 2, 1, 1};
    float* sumArray = new float [arrayLength];
    
    for (int k = 0; k < 10; k++) {
        std::cout << *(sumArray+k) << " ";
    }
    std::cout << std::endl;
    
    addarrays(array1, array2, sumArray, arrayLength);
    
    for (int k = 0; k < 10; k++) {
        std::cout << *(sumArray+k) << " ";
    }
    std::cout << std::endl;
}