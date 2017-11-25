// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <cstring>
#include <string>
#include <algorithm>
#include <cassert>
#include <cstdint>

//递归算法

int64_t Exponentiation1(int64_t x, int64_t n, int64_t mod) {
  if (n < 0)
    return Exponentiation1(x % mod, -n, mod) % mod;
  else if (n == 0)
    return 1L;
  else if (n == 1)
    return x % mod;
  else if (n % 2)
    return x * Exponentiation1(x * x % mod, (n - 1) / 2, mod) % mod;
  else
    return Exponentiation1(x * x % mod, n / 2, mod) % mod;
}

//二进制非递归算法

int64_t Exponentiation2(int64_t x, int64_t n, int64_t mod) {
  int64_t exp = 1L;
  while (n > 0) {
    if (n & 1)
      exp = (exp * x) % mod;
    x = (x * x) % mod;
    // n /= 2
    n >>= 1;
  }
  return exp;
}
