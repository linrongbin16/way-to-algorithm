#include "SegmentTree.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

#define TEST_MAX 1024

int main()
{
    int s[MAX];
    for (int i = 0; i < MAX; i++) {
        s[i] = i;
    }
    for (int i = 0; i < MAX; i++) {
        SegmentTreeInit(0, s, 0, MAX-1);
        for (int j = 0; j < MAX; j++) {
            int sum = 0;
            SegmentTreeAdd(0, j, j);
            for (int k = 0; k < MAX; k++) {
                sum += k;
                if (k < j) {
                    assert(SegmentTreeQuery(0, 0, k) == sum);
                } else {
                    assert(SegmentTreeQuery(0, 0, k) == sum + j);
                }
            }
            SegmentTreeAdd(0, j, -j);
        }
    }

    return 0;
}

