#include "Euclid.h"

int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  }
  return GreatestCommonDivisor(b, a % b);
}

int LeastCommonMultiple(int a, int b) {
  int gcd = GreatestCommonDivisor(a, b);
  return gcd * (a / gcd) * (b / gcd);
}

