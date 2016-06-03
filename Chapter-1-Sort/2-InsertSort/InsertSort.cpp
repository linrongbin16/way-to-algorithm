#include "InsertSort.hpp"
#include <iostream>
#include <cassert>
using namespace std;


void AssertNotAscendingOrder(int s[MAX], int n)
{
    bool res = true;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] > s[i+1]) {
            res = false;
            break;
        }
    }
    assert(!res);
}
void AssertAscendingOrder(int s[MAX], int n)
{
    bool res = true;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] > s[i+1]) {
            res = false;
            break;
        }
    }
    assert(res);
}
void AssertInsertSort(int s[MAX], int n)
{
    AssertNotAscendingOrder(s, n);
    InsertSort(s, 0, n);
    AssertAscendingOrder(s, n);
}

int main()
{
    int s1[60] = {
        234, 10, -41, 0, 34, 15, 64, 653, -745, 74,
        65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
        134, 10, -41, 801, 32, 25, 63, 653, -715, 18,
        65, 36, 987, -875, -21, -4861, 24, 16, 64, 46,
        234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
        13, 33, 387, -875, -90, -8871, 77, 66, 66, 34,
    };

    int s2[20] = {
        234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
        65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
    };

    int s3[2] = { 154, 46 };

    int s4[50] = {
        234, 10, -41, 0, 34, 15, 64, 653, -745, 74,
        65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
        134, 10, -41, 801, 32, 25, 63, 653, -715, 18,
        65, 36, 987, -875, -21, -4861, 24, 16, 64, 46,
        234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
    };

    AssertInsertSort(s1, 0, 60);
    AssertInsertSort(s2, 0, 20);
    AssertInsertSort(s3, 0, 2);
    AssertInsertSort(s4, 0, 50);

    return 0;
}
