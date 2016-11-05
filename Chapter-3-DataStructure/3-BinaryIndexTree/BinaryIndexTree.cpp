#include "BinaryIndexTree.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

#define TEST_MAX 1024

int main()
{
    for (int i = 0; i < TEST_MAX; i++) {
        BinaryIndexTree *t = BinaryIndexTreeNew();
        assert(t);
        int sum = 0;
        for (int j = 1; j < MAX; j++) {
            BinaryIndexTreeAdd(t, j, i);
            sum += i;
            assert(BinaryIndexTreeSum(t, MAX-1) == sum);
        }
    }

    return 0;
}
