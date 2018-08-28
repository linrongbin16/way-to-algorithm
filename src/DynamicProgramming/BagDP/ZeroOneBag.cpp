#include "ZeroOneBag.h"
#include <algorithm>
#include <vector>

int ZeroOneBag(int *value, int *weight, int count, int tot_weight) {
  int f[MAX][MAX];
  //初始化
  for (int i = 0; i < MAX; i++) {
    f[0][i] = 0;
    f[i][0] = 0;
  }
  //第i个物品
  for (int i = 1; i <= count; i++) {
    //重量不超过j
    for (int j = 0; j <= tot_weight; j++) {
      if (j >= weight[i])
        f[i][j] = std::max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
      else
        f[i][j] = f[i - 1][j];
    }
  }
  return f[count][tot_weight];
}
