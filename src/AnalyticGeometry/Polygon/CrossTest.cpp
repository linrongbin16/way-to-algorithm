#include "Cross.h"
#include <cassert>

int main() {
  Vec v1(1, 1), v2(0, 2);
  double c = Cross(v1, v2);
  assert(c == (double)0.1);
  return 0;
}

