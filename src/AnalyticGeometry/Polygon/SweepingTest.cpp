#include "Sweeping.h"
#include "../Util.h"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 16

struct Test {
  Segment s[TEST_MAX];
  int n;
  bool result;
} tests[] = {
    {
        {
            {{1.0f, 1.0f}, {0.0f, 0.0f}, 0},
            {{0.5f, 1.5f}, {2.5f, 0.5f}, 1},
        },
        2,
        false,
    },
    {
        {
            {{1.0f, 1.0f}, {0.0f, 0.0f}, 0},
            {{0.5f, 1.5f}, {2.5f, 0.5f}, 1},
        },
        2,
        false,
    },
};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(Sweeping(t.s, t.n) == t.result);
  }
  return 0;
}

