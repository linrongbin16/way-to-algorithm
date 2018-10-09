#include "LongestCommonSubsequence.h"
#include <cassert>
using namespace std;

#define TEST_MAX 1024

struct Test {
  int a[TEST_MAX];
  int b[TEST_MAX];
  int n;
  int result;
} test_cases[] = {
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {0, 1, 3, 5, 7, 9, 11, 13, 15, 17},
        10,
        5,
    },
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9},
        10,
        5,
    },
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        10,
        1,
    },
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {0, 1, 2, 8, 7, 4, 3, 4, 3, 2, 1},
        10,
        4,
    },
    {
        {0, 1, 1, 5, 4, 9, 7, 31, -13, 34, 21, 17},
        {0, 5, 6, 11, 4, 9, 0, 34, 21, -13, 17, 3},
        11,
        6,
    },
    {
        {0, 12, 142, -5, 14, 15,  45, 42,  61, 41,
         0, 42, 42,  -5, 14, 215, 45, -42, 1,  31},
        {0, 42, 42,  -5, 14, 215, 45, -42, 1,  31,
         0, 12, 142, -5, 14, 15,  45, 42,  61, 41},
        19,
        9,
    },
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    int r = LongestCommonSubsequence(t.a, t.b, t.n);
    assert(r == t.result);
  }

  return 0;
}

