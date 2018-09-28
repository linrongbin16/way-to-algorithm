#include "Euclid.h"

int GreatestCommonDivisor(int a, int b) {
  if (a % b == 0) {
    return b;
  }
  return GreatestCommonDivisor(b, a % b);
}

int LeastCommonMultiple(int a, int b) {
  int gcd = GreatestCommonDivisor(a, b);
  int c = a / gcd;
  int d = b / gcd;
  return gcd * c * d;
}

