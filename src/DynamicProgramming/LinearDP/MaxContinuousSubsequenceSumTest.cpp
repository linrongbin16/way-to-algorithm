#include "MaxContinuousSubsequenceSum.h"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct Test {
  int s[TEST_MAX];
  int n;
  int result;
} test_cases[] = {
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        10,
        55,
    },
    {
        {0, 1, -2, 3, -4, -5, -6, 7, 18, -9, 10},
        10,
        26,
    },
    {
        {0, 7, -2, 23, -4, -15, -6, 7, 38, -19, 20},
        10,
        49,
    },
    {
        {0, 12, 142, -125, 14, 15,  45, 42,  61, 41,
         0, 42, 42,  -205, 14, 215, 45, -42, 1,  31},
        19,
        390,
    },
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    int r = MaxContinuousSubsequenceSum(t.s, t.n);
    assert(r == t.result);
  }

  return 0;
}

