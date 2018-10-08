#include "ZeroOneBag.h"
#include "Util.h"
#include <algorithm>
#include <vector>

int ZeroOneBag(int *v, int *w, int n, int weight) {
  //初始化

  int **f = Array2DNew(n + 1, weight + 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= weight; j++)
      f[i][j] = 0;

  //第i个物品

  for (int i = 1; i <= n; i++) {

    //重量不超过j

    for (int j = 0; j <= weight; j++) {

      if (j >= w[i]) {
        f[i][j] = std::max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
      } else {
        f[i][j] = f[i - 1][j];
      }
    }
  }

  int result = f[n][weight];
  Array2DFree(f, n + 1);
  return result;
}

