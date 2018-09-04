#include "Cross.h"
#include "../Util.h"
#include <cassert>
#include <iostream>
using namespace std;

struct Test {
  Vec v1;
  Vec v2;
  double result;
} tests[] = {
    {{1.0f, 1.0f}, {0.0f, 2.0f}, 2.0f},
    {{-1.0f, 0.0f}, {0.5f, -1.3f}, 1.3f},
    {{1.4f, -0.8f}, {0.5f, 1.1f}, 1.94f},
    {{1.8f, -8.0f}, {0.3f, 2.0f}, 6.0f},
};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(FloatEq(Cross(t.v1, t.v2), t.result));
  }
  return 0;
}

