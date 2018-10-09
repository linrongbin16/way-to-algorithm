#include "UniquePath.h"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
using namespace std;

struct Test {
  int s[MAX][MAX];
  int n;
  int m;
  int result;
} test_cases[] = {
    {
        {
            {0, 1, 2, 3},
            {},
        },
        3,
        4,
        11,
    },
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    int r = UniquePath(t.s, t.n, t.m);
    assert(r == t.result);
  }

  return 0;
}

