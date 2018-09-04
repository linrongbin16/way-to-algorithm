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
            {{0.0f, 0.0f, 0}, {1.0f, 1.0f, 1}, 0},
            {{0.5f, 1.5f, 2}, {2.5f, 0.5f, 3}, 1},
        },
        2,
        false,
    },
    {
        {
            {{0.0f, 0.0f, 0}, {1.0f, 1.0f, 1}, 0},
            {{0.0f, 1.0f, 2}, {1.0f, 0.1f, 3}, 1},
        },
        2,
        true,
    },
    {
        {
            {{0.0f, 0.0f, 0}, {2.0f, 2.0f, 1}, 0},
            {{0.5f, 1.0f, 2}, {0.5f, 2.1f, 3}, 1},
            {{1.0f, 1.5f, 4}, {4.0f, 1.3f, 5}, 2},
            {{3.0f, 1.0f, 6}, {4.0f, -0.2f, 7}, 3},
            {{3.1f, 0.0f, 8}, {5.5f, 5.8f, 9}, 4},
        },
        5,
        true,
    },
    {
        {
            {{0.0f, 0.0f, 0}, {1.0f, 1.0f, 1}, 0},
            {{0.0f, 2.0f, 2}, {2.0f, 2.1f, 3}, 1},
            {{0.5f, -0.1f, 4}, {3.0f, 0.1f, 5}, 3},
            {{1.0f, 1.5f, 6}, {3.0f, 0.9f, 7}, 4},
        },
        4,
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

