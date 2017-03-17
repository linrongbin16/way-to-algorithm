#include "LongestCommonSubsequence.hpp"
#include <cassert>

#define TEST_MAX 1024

struct Test {
    int a[MAX];
    int b[MAX];
    int n;
    int result;
} test_cases[] = {
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 0, 1, 3, 5, 7, 9, 11, 13, 15, 17 }, 
        10, 5
    },
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 }, 
        10, 5
    },
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, 
        10, 1
    },
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 0, 1, 2, 8, 7, 4, 3, 4, 3, 2, 1 }, 
        10, 4
    },
};


int main()
{
    int count = sizeof(test_cases) / sizeof(Test);
    for (int i = 0; i < count; i++) {
        Test & t = test_cases[i];
        int r = LongestCommonSubsequence(t.a, t.b, t.n);
        assert(r == t.result);
    }

    return 0;
}
