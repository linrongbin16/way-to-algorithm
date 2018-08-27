#include "CompleteKnapsack.hpp"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct ZOKTest {
    int value[MAX];
    int weight[MAX];
    int count;
    int total_weight;
    int result;
} test_cases[] = {
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {0, 1, 3, 5, 7, 9, 11, 13, 15, 17, 10},
        10,
        30,
        30,
    },  // 0
    {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
     {0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9},
     10,
     20,
     120},  // 1
    {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
     {0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
     10,
     25,
     250},  // 2
    {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
     {0, 1, 2, 8, 7, 4, 3, 4, 3, 2, 1},
     10,
     20,
     200},  // 3
    {{0, 1, 1, 5, 4, 9, 7, 31, 13, 34, 21, 17},
     {0, 5, 6, 11, 4, 9, 2, 34, 21, 13, 17, 3},
     11,
     50,
     279},  // 4
    {{0, 12, 142, 5,  14, 15,  45, 42, 61, 41,
      0, 42, 42,  25, 14, 215, 45, 42, 1,  31},
     {0, 42, 42,  5, 14, 215, 45, 42, 3,  31,
      1, 12, 142, 5, 14, 15,  45, 42, 61, 41},
     19,
     80,
     1586},  // 5
};

int main() {
    int count = sizeof(test_cases) / sizeof(ZOKTest);
    for (int i = 0; i < count; i++) {
        ZOKTest& t = test_cases[i];
        int r = CompleteKnapsack(t.value, t.weight, t.count, t.total_weight);
        // cout << i << ": " << r << endl;
        assert(r == t.result);
    }

    return 0;
}
