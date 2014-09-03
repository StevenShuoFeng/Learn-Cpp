//Exercise 10.1

#include <iostream>

int main(){
    char ifMore = 'y';
    float* startPtr = new float();
    int numElement = 0;
    
    while (ifMore != 'n')
    {
        std::cout << "Enter a number:\n";
        std::cin >> *(startPtr+numElement++);
        
        std::cout << "Want another number (y/n)?\n";
        std::cin >> ifMore;
    }
    
    std::cout << "The numbers you've entered are: \n";
    for (int k = 0; k < numElement; k++) {
        std::cout << *(startPtr+k) << std::endl;
    }
    
    float getFloatAverage(float* startPtr, int arrayLength);
    std::cout << "Their avearage value is " << getFloatAverage(startPtr, numElement);
    std::cout << std::endl;
    
    delete[] startPtr;
    return 0;
}

float getFloatAverage(float* startPtr, int arrayLength)
{
    float arraySum = 0;
    for (int k = 0; k < arrayLength; k++) {
        arraySum += *(startPtr+k);
    }
    return arraySum/arrayLength;
}