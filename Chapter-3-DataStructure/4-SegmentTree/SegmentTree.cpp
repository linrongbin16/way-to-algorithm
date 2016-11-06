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
        int sum = 0;
        SegmentTreeAdd(0, i, i);
        for (int j = 0; j < MAX; j++) {
            sum += j;
            if (j < i) {
                assert(SegmentTreeQuery(0, 0, j) == sum);
            } else {
                assert(SegmentTreeQuery(0, 0, j) == sum + i);
            }
        }
    }

    return 0;
}

