#include "LargeNumber.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

int main() {
  for (int i = 0; i < MAX; i++) {
    int a = rand();
    int b = rand();
    a = (rand() % 2 == 0) ? a : (-a);
    b = (rand() % 2 == 0) ? b : (-b);
    assert(Add(Number(a), Number(b)) == Number(a + b));
    assert(Sub(Number(a), Number(b)) == Number(a - b));
    assert(Mul(Number(a), Number(b)) == Number(a * b));
    assert(ToString(Add(Number(a), Number(b))) == ToString(Number(a + b)));
    assert(ToString(Sub(Number(a), Number(b))) == ToString(Number(a - b)));
    assert(ToString(Mul(Number(a), Number(b))) == ToString(Number(a * b)));
  }
  return 0;
}

