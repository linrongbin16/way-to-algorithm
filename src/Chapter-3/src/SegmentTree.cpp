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
        SegmentTree *t = SegmentTreeNew(s, 0, MAX-1);
        for (int j = 0; j < MAX; j++) {
            int sum = 0;
            SegmentTreeAdd(t, j, j);
            for (int k = 0; k < MAX; k++) {
                sum += k;
                if (k < j) {
                    assert(SegmentTreeQuery(t, 0, k) == sum);
                } else {
                    assert(SegmentTreeQuery(t, 0, k) == sum + j);
                }
            }
            SegmentTreeAdd(t, j, -j);
        }
        SegmentTreeFree(t);
    }

    return 0;
}

