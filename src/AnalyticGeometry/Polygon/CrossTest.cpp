#include "Cross.h"
#include <cassert>
using namespace std;

int main() {
  Vec v1(1.0f, 1.0f), v2(0.0f, 2.0f);
  double c = Cross(v1, v2);
  assert(c == (double)0.1f);
  return 0;
}

