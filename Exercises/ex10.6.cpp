//
//  ex10.6.cpp
//  Learn C++
//
//  Created by Shuo Feng on 9/5/14.
//  Copyright (c) 2014 Shuo Feng. All rights reserved.
//

#include <iostream>
#include "string.h"


int cmpstr(const char* s1, const char* s2){
    
    if (s1==NULL || s2==NULL) {
        std::cout << "Invald input string. \n";
        return -2;
    }

            
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    if (len1 == 0)
    {
        std::cout << "First string is empty.\n";
        return 1;
    }
    else if (len2 == 0)
    {
        std::cout << "Second string is empty. \n";
        return -1;
    }
    
    size_t minLen = len1>len2?len2:len1;
    
    bool compNext = true;
    int charCount = 0;
    while (compNext && charCount < minLen)
    {
        std::cout << "Comparing charactor " << charCount+1 << std::endl;
        if (*(s1+charCount) == *(s2+charCount))
        {
            std::cout << "Same Character " <<  *(s1+charCount) << ".. \n";
            compNext = true;
            charCount++;
        }
        else
        {
            compNext = false;
            if(*(s1+charCount) > *(s2+charCount))
            {
                std::cout << *(s2+charCount) << " comes first.. \n";
                return 1;
            }
            else
            {
                std::cout << *(s1+charCount) << " comes smaller.. \n";
                return -1;
            }
        }
    }
    
    if (compNext && charCount == minLen) {
        if (len1 == len2) {
            std::cout << "Two strings are excatlly the same: ";
            std::cout << s1 << " and " << s2 << std::endl;
            return 0;
        }
        else if (len1 == minLen)
        {
            std::cout << "Same characters, but the first string is short.\n";
            return -1;
        }
        else
        {
            std::cout << "Same characters, but the second string is short.\n";
            return 1;
        }
    }
    
    std::cout << "Unexpected ending.\n";
    return -2;
}

int main()
{
    const char* s1  = "Apples";
    const char* s2 = "Apples";
    int compareResult = cmpstr(s1,s2);
    if (compareResult == -1)
        std::cout << s1 << " comes frist\n";
    else if(compareResult == 1)
        std::cout << s2 << " comes frist\n";
    else
        std::cout << s1 << " and " << s2 << " are the same.\n";
}