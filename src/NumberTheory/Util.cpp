#include "Util.h"
#include <algorithm>
#include <cassert>
#include <iostream>

void AssertGcd(int a, int b, int gcd) {
  assert(a > 0);
  assert(b > 0);
  assert(gcd > 0);
  assert(a % gcd == 0);
  assert(b % gcd == 0);
  for (int i = gcd + 1; i < a && i < b; i++) {
    assert(!(a % i == 0 && b % i == 0));
  }
}

void AssertLcm(int a, int b, int lcm) {
  assert(a > 0);
  assert(b > 0);
  assert(lcm > 0);
  assert(lcm % a == 0);
  assert(lcm % b == 0);
  for (int i = std::max(a, b) + 1; i < lcm; i++) {
    assert(!(i % a == 0 && i % b == 0));
  }
}

