#include "CompleteBag.h"
#include "../Util.h"
#include <algorithm>
#include <vector>

int CompleteBag(const int *v, const int *w, int n, int weight) {

  // 初始化

  int **f = Array2DNew(n + 1, weight + 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= weight; j++)
      f[i][j] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= weight; j++) {

      // 珠宝i最多可以装count个

      int count = j / w[i];

      for (int k = 0; k <= count; k++) {
        f[i][j] = std::max(f[i - 1][j], f[i - 1][j - k * w[i]] + k * v[i]);
      }
    }
  }

  int result = f[n][weight];
  Array2DFree(f, n + 1);
  return result;
}

