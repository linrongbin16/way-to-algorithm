#include "Euclid.h"
#include "Util.h"
#include <cassert>
#include <cstdlib>

#define MAX 4096

int main(void) {
  for (int i = 0; i < MAX; i++) {
    int a = abs(rand() % MAX);
    int b = abs(rand() % MAX);
    int gcd = GreatestCommonDivisor(a, b);
    int lcm = LeastCommonMultiple(a, b);
    AssertGcd(a, b, gcd);
    AssertLcm(a, b, lcm);
  }
  return 0;
}

