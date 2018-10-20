#include "ModularLinearEquations.h"
#include <cassert>
#include <iostream>

#define MAX 1024

struct Test {
  int a[MAX];
  int m[MAX];
  int n;
  int result;
} test_cases[] = {
    {
        {1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4},
        5,
        480,
    },
    {
        {1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4},
        5,
        480,
    },
    {
        {1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4},
        5,
        480,
    },
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    int x = ModularLinearEquations(t.a, t.m, t.n);
    assert(x == t.result);
  }
  return 0;
}

