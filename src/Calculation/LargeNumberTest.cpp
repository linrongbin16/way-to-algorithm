#include "LargeNumber.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

#define TEST_MAX 1024

double RandDouble() {
  double up, down;
  do {
    up = (double)rand();
  } while (up == 0.0);
  do {
    down = (double)rand();
  } while (down == 0.0);
  return up / down;
}

int main() {
  Number a, b;

  for (int i = 0; i < TEST_MAX; i++) {
    int a = rand();
    int b = rand();
    assert(Init(a) + Init(b) == Init(a + b));
    assert(Init(a) - Init(b) == Init(a - b));
    assert(Init(a) * Init(b) == Init(a * b));
    assert(ToString(Init(a) + Init(b)) == ToString(Init(a + b)));
    assert(ToString(Init(a) - Init(b)) == ToString(Init(a - b)));
    assert(ToString(Init(a) * Init(b)) == ToString(Init(a * b)));

    double c = RandDouble(), d = RandDouble();
    assert(Init(c) + Init(d) == Init(c + d));
    assert(Init(c) - Init(d) == Init(c - d));
    assert(Init(c) * Init(d) == Init(c * d));
    assert(ToString(Init(c) + Init(d)) == ToString(Init(c + d)));
    assert(ToString(Init(c) - Init(d)) == ToString(Init(c - d)));
    assert(ToString(Init(c) * Init(d)) == ToString(Init(c * d)));
  }

  return 0;
}

