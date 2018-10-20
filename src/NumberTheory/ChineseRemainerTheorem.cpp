#include "ChineseRemainerTheorem.h"
#include "Euclid.h"
#include <cstring>

int ChineseRemainerTheorem(int *a, int *m, int n) {
  int M = 1;
  for (int i = 0; i < n; i++) {
    M *= a[i];
  }

  int Mi[MAX];
  int t[MAX];
  std::memset(Mi, 0, sizeof(int) * MAX);
  std::memset(t, 0, sizeof(int) * MAX);
  for (int i = 0; i < n; i++) {
    Mi[i] = M / m[i];
    t[i] = GreatestCommonDivisor(Mi[i], m[i]);
  }

  int x = 0;
  for (int i = 0; i < n; i++) {
    x += a[i] * t[i] * Mi[i];
  }

  return x;
}

