#include "TrianglePath.h"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
using namespace std;

struct Test {
  int s[MAX];
  int k;
  int result;
} test_cases[] = {
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        10,
        10,
    },
    {
        {0, 1, 10, 2, 9, 3, 8, 4, 7, 5, 6},
        10,
        1,
    },
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    int r = TrianglePath(t.s, t.k);
    assert(r == t.result);
  }

  return 0;
}

