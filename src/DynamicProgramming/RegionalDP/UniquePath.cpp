#include "UniquePath.h"
#include "../Util.h"

int UniquePath(int s[MAX][MAX], int n, int m) {
  int **f = Array2DNew(n + 1, m + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = f[i - 1][j] + f[i][j - 1];
    }
  }

  int result = f[n][m];
  Array2DFree(f, n + 1);
  return result;
}

