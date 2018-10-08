#include "GreatestContinuousSubsequenceSum.h"
#include "../Util.h"
#include <algorithm>
#include <vector>

int GreatestContinuousSubsequenceSum(const int *s, int n) {
  int *f = ArrayNew(n + 1);

  for (int i = 0; i <= n; i++) {
    f[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    f[i] = std::max(f[i - 1] + s[i], s[i]);
  }

  int result = f[n];
  ArrayFree(f);
  return result;
}

