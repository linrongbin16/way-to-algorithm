#include "TwoDimensionBag.h"
#include "Util.h"
#include <algorithm>
#include <iostream>

int TwoDimensionBag(int *v, int *w1, int *w2, int n, int weight1, int weight2) {
  int ***f = Array3DNew(n + 1, weight1 + 1, weight2 + 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= weight1; j++)
      for (int k = 0; k <= weight2; k++)
        f[i][j][k] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= weight1; j++) {
      for (int k = 0; k <= weight2; k++) {
        if (j >= w1[i] && k >= w2[i]) {
          f[i][j][k] =
              std::max(f[i - 1][j][k], f[i - 1][j - w1[i]][k - w2[i]] + v[i]);
        } else {
          f[i][j][k] = f[i - 1][j][k];
        }
      }
    }
  }

  int result = f[n][weight1][weight2];
  Array3DFree(f, n + 1, weight1 + 1);
  return result;
}

