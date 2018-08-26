#include "Exponentiation.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <random>
using namespace std;


#define TEST_MAX 1024

struct Test {
  int64_t x;
  int64_t n;
  int64_t mod;
  int64_t result;
} tests[] = {
  { 1,  233512,   100000000,  1 },
  { 2,  2,        10000000,   4 },
};


int main(void) {

  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(Exponentiation1(t.x, t.n, t.mod) == t.result);
    assert(Exponentiation2(t.x, t.n, t.mod) == t.result);
  }

  return 0;
}

