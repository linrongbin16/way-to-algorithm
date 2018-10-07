#include "LargeNumber.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>

static void BuildBits(int *bits, int &len, long n) {
  std::memset(bits, 0, sizeof(int) * MAX);
  len = 0;
  n = (n < 0) ? (-n) : n;
  while (n) {
    bits[len++] = n % 10;
    n = n / 10;
  }
}

static bool IsZero(const Number &a) {
  if (a.len == 0) {
    return true;
  }
  for (int i = 0; i < a.len; i++) {
    if (a.bits[i] != 0)
      return false;
  }
  return true;
}

static Number Negative(const Number &a) {
  if (IsZero(a)) {
    return a;
  }
  Number c(a);
  c.negative = !c.negative;
  return c;
}

Number::Number() {
  negative = false;
  BuildBits(bits, len, 0);
}

Number::Number(int a) {
  negative = (a < 0) ? true : false;
  BuildBits(bits, len, (long)a);
}

Number::Number(long a) {
  negative = (a < 0) ? true : false;
  BuildBits(bits, len, a);
}

Number::Number(const Number &other) {
  std::memcpy(bits, other.bits, sizeof(int) * MAX);
  len = other.len;
  negative = other.negative;
}

Number &Number::operator=(const Number &other) {
  if (this == &other)
    return *this;
  std::memcpy(bits, other.bits, sizeof(int) * MAX);
  len = other.len;
  negative = other.negative;
  return *this;
}

Number Add(const Number &a, const Number &b) {
  if (a.negative != b.negative) {
    return Sub(a, Negative(b));
  }
  Number c;
  int n = std::max(a.len, b.len) + 1;
  for (int i = 0; i < n; i++) {
    c.len++;
    c.bits[i] = (c.bits[i] + a.bits[i] + b.bits[i]) % 10;
    c.bits[i + 1] = c.bits[i + 1] + (a.bits[i] + b.bits[i]) / 10;
  }
  while (c.len - 1 >= 0 && c.bits[c.len - 1] == 0) {
    c.len--;
  }
  c.negative = a.negative;
  return c;
}

static bool Greater(const Number &a, const Number &b) {
  if (IsZero(a) && IsZero(b)) {
    return true;
  }
  if (a.negative != b.negative) {
    return !a.negative;
  }
  if (a.negative) {
    int n = std::max(a.len, b.len) + 1;
    for (int i = n - 1; i >= 0; i--) {
      if (a.bits[i] != b.bits[i]) {
        return a.bits[i] < b.bits[i];
      }
    }
  } else {
    int n = std::max(a.len, b.len) + 1;
    for (int i = n - 1; i >= 0; i--) {
      if (a.bits[i] != b.bits[i]) {
        return a.bits[i] > b.bits[i];
      }
    }
  }
  return false;
}

static bool Eq(const Number &a, const Number &b) {
  if (a.len != b.len)
    return false;
  if (a.negative != b.negative)
    return false;
  return std::memcmp(a.bits, b.bits, MAX * sizeof(int)) == 0;
}

static bool GreaterEq(const Number &a, const Number &b) {
  return Greater(a, b) || Eq(a, b);
}

Number Sub(const Number &a, const Number &b) {
  if (a.negative != b.negative) {
    return Add(a, Negative(b));
  }
  if (GreaterEq(b, a)) {
    return Negative(Sub(b, a));
  }

  Number aa(a);
  Number c;
  int n = std::max(a.len, b.len) + 1;
  for (int i = 0; i < n; i++) {
    c.len++;
    if (aa.bits[i] >= b.bits[i]) {
      c.bits[i] = c.bits[i] + aa.bits[i] - b.bits[i];
    } else {
      c.bits[i] = c.bits[i] + aa.bits[i] + 10 - b.bits[i];
      aa.bits[i + 1] = aa.bits[i + 1] - 1;
    }
  }
  while (c.len - 1 >= 0 && c.bits[c.len - 1] == 0) {
    c.len--;
  }
  return c;
}

Number Mul(const Number &a, const Number &b) {
  Number c;
  for (int j = 0; j < b.len; j++) {
    for (int i = 0; i < a.len; i++) {
      c.len++;
      c.bits[(int)std::pow(10, j) + i] =
          (c.bits[(int)std::pow(10, j) + i] + a.bits[i] + b.bits[j]) % 10;
      c.bits[(int)std::pow(10, j) + i + 1] =
          c.bits[(int)std::pow(10, j) + i + 1] +
          (c.bits[(int)std::pow(10, j) + i] + a.bits[i] + b.bits[j]) / 10;
    }
  }
  while (c.len - 1 >= 0 && c.bits[c.len - 1] == 0) {
    c.len--;
  }
  if (a.negative != b.negative) {
    c.negative = false;
  } else {
    c.negative = true;
  }
  return c;
}

Number Div(const Number &a, const Number &b) { return Number(); }

std::string ToString(const Number &a) {
  std::string s;
  for (int i = a.len - 1; i >= 0; i--) {
    s = s + std::to_string(a.bits[i]);
  }
  return s;
}

bool operator==(const Number &a, const Number &b) {
  if (a.len != b.len)
    return false;
  if (a.negative != b.negative)
    return false;
  return std::memcmp(a.bits, b.bits, MAX * sizeof(int)) == 0;
}

bool operator!=(const Number &a, const Number &b) { return !(a == b); }

