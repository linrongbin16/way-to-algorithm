#include "BidirectionalSubsequence.h"
#include "../Util.h"
#include <algorithm>

static void LongestIncreasingSubsequence(int *f, const int *s, int n) {
  for (int i = 0; i <= n; i++) {
    f[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    int maxlen = 0;
    for (int k = 1; k < i; k++) {
      if (s[i] > s[k])
        maxlen = std::max(maxlen, f[k]);
    }
    f[i] = maxlen + 1;
  }
}

static void LongestDecreasingSubsequence(int *g, const int *s, int n) {
  for (int i = 0; i <= n; i++) {
    g[i] = 0;
  }

  for (int i = n; i >= 1; i--) {
    int maxlen = 0;
    for (int k = n; k > i; k--) {
      if (s[i] > s[k])
        maxlen = std::max(maxlen, g[k]);
    }
    g[i] = maxlen + 1;
  }
}

int BidirectionalSubsequence(const int *s, int n) {
  int *f = ArrayNew(n + 1);
  int *g = ArrayNew(n + 1);
  LongestIncreasingSubsequence(f, s, n);
  LongestDecreasingSubsequence(g, s, n);

  int bimax = 0;
  for (int i = 1; i <= n; i++) {
    bimax = std::max(f[i] + g[i] - 1, bimax);
  }

  ArrayFree(f);
  ArrayFree(g);
  return bimax;
}

