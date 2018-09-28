#include "Euclid.h"

int GreatestCommonDivisor(int a, int b) {
  return (a % b == 0) ? b : GreatestCommonDivisor(b, a % b);
}

int LeastCommonMultiple(int a, int b) {
  int gcd = GreatestCommonDivisor(a, b);
  return gcd * (a / gcd) * (b / gcd);
}

