#include "Euclid.h"
#include <cassert>

struct Test {
  int a;
  int b;
  int gcd;
  int lcm;
} tests[] = {
    {1, 1, 1, 1},
    {36, 66, 6, 396},
    {16, 11, 1, 176},
};

int main(void) {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(GreatestCommonDivisor(t.a, t.b) == t.gcd);
    assert(LeastCommonMultiple(t.a, t.b) == t.lcm);
  }
  return 0;
}

