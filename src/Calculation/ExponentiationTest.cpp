#include "Exponentiation.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

#define TEST_MAX 1024
#define PRIME 10000019L

int64_t GetExp(int64_t x, int64_t n, int64_t mod) {
  int64_t result = 1;
  for (int64_t i = 0; i < n; i++) {
    result = (result * x) % mod;
  }
  return result;
}

int main(void) {
  for (int i = 0; i < TEST_MAX; i++) {
    int64_t x = rand();
    int64_t n = rand();
    int64_t result = Exponentiation(x, n, PRIME);
    assert(result == GetExp(x, n, PRIME));
  }
  return 0;
}

