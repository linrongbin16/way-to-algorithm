#include "UniquePath.h"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
using namespace std;

struct Test {
  int n;
  int m;
  int result;
} test_cases[] = {
    {3, 4, 10}, {1, 5, 1},  {9, 1, 1},  {2, 8, 8},  {7, 6, 462},
    {4, 7, 84}, {5, 9, 495}, {8, 7, 1716}, {9, 6, 1287}, {7, 8, 1716},
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    int r = UniquePath(t.n, t.m);
    assert(r == t.result);
  }

  return 0;
}

