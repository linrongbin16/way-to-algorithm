#include "MaximumTreeMerge.hpp"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct TMTest {
    int s[MAX];
    int n;
    int result;
} test_cases[] = {
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7 },
        7, 544
    },      // 0
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        5, 30
    },      // 1
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        5, 30
    },      // 2
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        5, 30
    },      // 3
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        5, 30
    },      // 4
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        5, 30
    },      // 5
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        5, 30
    },      // 6
};


int main()
{
    int count = sizeof(test_cases) / sizeof(TMTest);
    for (int i = 0; i < count; i++) {
        TMTest & t = test_cases[i];
        int r = MaximumTreeMerge(t.s, t.n);
        cout << i << ": " << r << endl;
        assert(r == t.result);
    }

    return 0;
}