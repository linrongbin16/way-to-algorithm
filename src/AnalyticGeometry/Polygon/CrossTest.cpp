#include "Cross.h"
#include <cassert>
using namespace std;

struct Test {
  Vec v1;
  Vec v2;
  double result;
} tests[] = {{{1.0f, 1.0f}, {0.0f, 2.0f}, 0.1f}};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(Cross(t.v1, t.v2) == t.result);
  }
  return 0;
}

