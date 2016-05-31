#include "BinarySearch.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


void AssertElementExist(int s[MAX], int beg, int end, int x)
{
    int index = -1; 
    assert(BinarySearch(s, beg, end, x, index)); 
    assert(index >= beg); 
    assert(index < end);
}
void AssertElementNotExist(int s[MAX], int beg, int end, int x)
{
    int index = -1; 
    assert(!BinarySearch(s, beg, end, x, index)); 
    assert(index == -1);
}

int main()
{
    int s1[60] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };
    int s2[20] = {
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };
    int s3[1] = { 1 };
    int s4[50] = {
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    };

    for (int i = -60; i < 100; ++i) { 
        if (i >= 0 && i < 60) 
            AssertElementExist(s1, 0, 60, i); 
        else 
            AssertElementNotExist(s1, 0, 60, i); 
    } 
    for (int i = 0; i < 100; ++i) { 
        if ((i >= 20 && i < 30) || (i >= 50 && i < 60)) 
            AssertElementExist(s2, 0, 20, i); 
        else 
            AssertElementNotExist(s2, 0, 20, i); 
    } 
    for (int i = -10; i < 10; ++i) { 
        if (i == 1) 
            AssertElementExist(s3, 0, 1, i); 
        else 
            AssertElementNotExist(s3, 0, 1, i); 
    } 
    for (int i = -60; i < 100; ++i) { 
        if (i >= 0 && i < 50) 
            AssertElementExist(s4, 0, 50, i); 
        else 
            AssertElementNotExist(s4, 0, 50, i); 
    }
    return 0;
}


