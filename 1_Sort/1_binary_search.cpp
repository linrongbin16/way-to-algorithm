#include "1_binary_search.h"
#include <iostream>
using namespace std;


void printArray(int s[], int n, const char *msg)
{
    cout << msg << endl;
    for (int i = 0; i < n; ++i) {
        cout << s[i] << ' ';
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl << endl;
}

void findElement(int s[], int n, const char *strname)
{
    cout << strname << ":" << endl;

    int index = -1;
    cout << "find 1 in "  << strname << ": "; 
    cout << binary_search(s, 0, n, 1, index);
    cout << ", index: " << index << endl;

    index = -1;
    cout << "find 20 in "  << strname << ": "; 
    cout << binary_search(s, 0, n, 20, index);
    cout << ", index: " << index << endl;

    index = -1;
    cout << "find 36 in "  << strname << ": "; 
    cout << binary_search(s, 0, n, 36, index);
    cout << ", index: " << index << endl;

    index = -1;
    cout << "find 50 in "  << strname << ": "; 
    cout << binary_search(s, 0, n, 50, index);
    cout << ", index: " << index << endl;

    index = -1;
    cout << "find 59 in "  << strname << ": "; 
    cout << binary_search(s, 0, n, 59, index);
    cout << ", index: " << index << endl;
}

int main()
{
    int s1[MAX] = {
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

    printArray(s1, MAX, "s1:");
    printArray(s2, 20, "s2:");
    printArray(s3, 1, "s3:");
    printArray(s4, 50, "s4:");

    findElement(s1, MAX, "s1");
    findElement(s2, 20, "s2");
    findElement(s3, 1, "s3");
    findElement(s4, 50, "s4");

    return 0;
}

