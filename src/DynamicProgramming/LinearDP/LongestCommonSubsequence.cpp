#include "LongestCommonSubsequence.h"
#include "../Util.h"
#include <algorithm>
#include <vector>

int LongestCommonSubsequence(const int *a, const int *b, int n) {
  int **f = Array2DNew(n + 1, n + 1);

  // 初始化
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i] == b[j])
        f[i][j] = f[i - 1][j - 1] + 1;
      else
        f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
    }
  }

  int result = f[n][n];
  Array2DFree(f, n + 1);
  return result;
}

