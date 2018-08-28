#include "BidirectionalSubsequence.h"
#include <algorithm>

static void LongestIncreasingSubsequence(int *f, int *g, const int *s, int n) {
  // 初始化
  f[0] = 0;
  for (int i = 1; i <= n; i++)
    f[i] = 1;

  for (int i = 1; i <= n; i++) {
    int max_length = 0;
    for (int k = 1; k < i; k++) {
      if (s[i] > s[k])
        max_length = std::max(max_length, f[k]);
    }
    f[i] = max_length + 1;
  }
}

static void LongestDecreasingSubsequence(int *f, int *g, const int *s, int n) {
  // 初始化
  g[0] = 0;
  for (int i = n; i >= 1; i--)
    g[i] = 1;

  for (int i = n; i >= 1; i--) {
    int max_length = 0;
    for (int k = n; k > i; k--) {
      if (s[i] > s[k])
        max_length = std::max(max_length, g[k]);
    }
    g[i] = max_length + 1;
  }
}

int BidirectionalSubsequence(const int *s, int n) {
  int f[MAX], g[MAX];
  LongestIncreasingSubsequence(f, g, s, n);
  LongestDecreasingSubsequence(f, g, s, n);

  int bimax = 0;
  for (int i = 1; i <= n; i++) {
    bimax = std::max(f[i] + g[i] - 1, bimax);
  }

  return bimax;
}

