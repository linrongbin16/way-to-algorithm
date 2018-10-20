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
    {1, 1, 0, 1, 1},
    {36, 66, 2, -1, 6},
    {16, 11, -2, 3, 1},
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

