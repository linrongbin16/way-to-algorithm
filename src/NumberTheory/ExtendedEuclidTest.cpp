#include "ExtendedEuclid.h"
#include <cassert>
#include <tuple>
using namespace std;

struct Test {
  int a;
  int b;
  int x;
  int y;
  int gcd;
} tests[] = {
    {1, 1, 1, 1},
    {36, 66, 6, 396},
    {16, 11, 1, 176},
};

int main(void) {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    tuple<int, int, int> result = ExtendedEuclid(t.a, t.b);
    assert(get<0>(result) == t.gcd);
    assert(get<1>(result) == t.x);
    assert(get<2>(result) == t.y);
  }
  return 0;
}

