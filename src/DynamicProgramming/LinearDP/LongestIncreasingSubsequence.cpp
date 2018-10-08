#include "LongestIncreasingSubsequence.h"
#include "../Util.h"
#include <algorithm>

int LongestIncreasingSubsequence(const int *s, int n) {
  int *f = ArrayNew(n + 1);

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

  int result = 0;
  for (int i = 1; i <= n; i++) {
    result = std::max(result, f[i]);
  }

  ArrayFree(f);
  return result;
}

