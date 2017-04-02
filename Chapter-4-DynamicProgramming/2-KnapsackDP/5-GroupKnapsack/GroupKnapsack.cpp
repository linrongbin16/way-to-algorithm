#include "GroupKnapsack.hpp"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct GKTest {
    Item group[MAX][MAX];
    int group_n[MAX];
    int n;
    int total_weight;
    int result;
} test_cases[] = {
    { 
        {
            { { 1, 1 }, { 2, 5 }, { 5, 10 }, { 3, 7 }, { 4, 5 } },
            { { 1, 1 }, { 2, 5 }, { 5, 10 }, { 3, 7 } },
            { { 1, 1 }, { 2, 5 }, { 5, 10 }, { 3, 7 }, { 4, 5 }, { 7, 10 } },
            { { 1, 1 }, { 2, 5 }, { 5, 10 }, { 3, 7 }, { 4, 5 }, { 9, 1 }, { 3, 3 } },
            { { 1, 1 }, { 2, 5 }, { 5, 10 } },
        }, 
        { 5, 4, 6, 7, 3 },
        5, 30, 41
    },      // 0
    { 
        {
            { { 1, 2 }, { 2, 4 }, { 3, 6 }, { 4, 8 }, { 5, 10 } },
            { { 10, 31 }, { 2, 5 }, { 5, 10 }, { 3, 7 } },
            { { 4, 7 }, { 2, 5 }, { 5, 10 }, { 3, 7 }, { 4, 5 }, { 7, 10 } },
            { { 9, 8 }, { 2, 5 }, { 6, 17 }, { 13, 7 } },
            { { 15, 21 }, { 32, 5 }, { 8, 10 } },
            { { 5, 1 }, { 32, 5 }, { 8, 10 } },
            { { 15, 21 }, { 2, 5 }, { 18, 13 } },
        }, 
        { 5, 4, 6, 4, 3, 3, 3 },
        7, 30, 41
    },      // 1
};


int main()
{
    int count = sizeof(test_cases) / sizeof(GKTest);
    for (int i = 0; i < count; i++) {
        GKTest & t = test_cases[i];
        int r = GroupKnapsack(t.group, t.group_n, t.n, t.total_weight);
        cout << i << ": " << r << endl;
        assert(r == t.result);
    }

    return 0;
}
