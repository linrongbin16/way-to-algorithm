#include "MinimumMergeCost.h"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct Test {
  int s[TEST_MAX];
  int n;
  int result;
} test_cases[] = {
    {
        {0, 1, 2, 3},
        3,
        9,
    },
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        10,
        219,
    },
    {
        {0, 1, 3, 5, 7, 9, 11, 13, 15, 17},
        8,
        203,
    },
    {
        {0, 1, 2, 3, 4, 5},
        5,
        34,
    },
    {
        {0, 1, 20, 3, 40, 5, 6, 7, 80, 90, 10},
        10,
        1011,
    },
    {
        {0, 5, 6, 11, 4, 9, 0, 34, 21, -13, 17, 3},
        11,
        556,
    },
    {
        {0, 1, 1, 5, 4, 9, 7, 31, -13, 34, 21, 17},
        11,
        466,
    },
    {
        {0, 42, 42,  -5, 14, 215, 45, -42, 1,  31,
         0, 12, 142, -5, 14, 15,  45, 42,  61, 41},
        19,
        7150,
    },
    {
        {0, 12, 142, -5, 14, 15,  45, 42,  61, 41,
         0, 42, 42,  -5, 14, 215, 45, -42, 1,  31},
        19,
        7420,
    },
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    int r = MinimumMergeCost(t.s, t.n);
    assert(r == t.result);
  }

  return 0;
}

