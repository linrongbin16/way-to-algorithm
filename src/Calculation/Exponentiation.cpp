#include "Exponentiation.h"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <string>

//#define odd(x) ((x) % 2 == 1)
//#define even(x) ((x) % 2 == 0)
#define odd(x) ((x)&1)
#define even(x) (!odd(x))

int64_t Exponentiation(int64_t x, int64_t n, int64_t mod) {
  assert(n >= 0);
  if (n == 0) {
    return 1L % mod;
  } else if (n == 1) {
    return x % mod;
  } else if (odd(n)) {
    // x^n = x * (x^2)^((n-1)/2)
    return (x * Exponentiation((x * x) % mod, (n - 1) / 2, mod)) % mod;
  } else if (even(n)) {
    // x^n = (x^2)^(n/2)
    return Exponentiation((x * x) % mod, n / 2, mod) % mod;
  } else {
    assert(!odd(n) && !even(n));
  }
}

