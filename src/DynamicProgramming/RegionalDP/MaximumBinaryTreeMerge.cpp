#include "MaximumBinaryTreeMerge.hpp"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct TMTest {
    int s[MAX];
    int n;
    int result;
} test_cases[] = {
    {{0, 1, 2, 3, 4, 5, 6, 7}, 7, 544},                    // 0
    {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 17935},       // 1
    {{0, 1, 10, 3, 8, 5, 6, 7, 4, 9, 2}, 10, 19671},       // 2
    {{0, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 10, 185274},  // 3
};

int main()
{
    int count = sizeof(test_cases) / sizeof(TMTest);
    for (int i = 0; i < count; i++) {
        TMTest& t = test_cases[i];
        int r = MaximumBinaryTreeMerge(t.s, t.n);
        cout << i << ": " << r << endl;
        assert(r == t.result);
    }

    return 0;
}
