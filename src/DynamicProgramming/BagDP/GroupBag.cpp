#include "GroupBag.h"
#include <algorithm>
#include <iostream>

static bool ItemCompare(const Item &a, const Item &b) {
  double rate_a = (double)a.value / (double)a.weight;
  double rate_b = (double)b.value / (double)b.weight;
  if (rate_a != rate_b)
    return rate_a > rate_b;
  else
    return a.weight < b.weight;
}

int GroupKnapsack(Item group[MAX][MAX], int *group_n, int n, int tot_weight) {
  // f[k][j] 前 k 组重量不超过 j 的最大价值
  int f[MAX][MAX];

  // 初始化
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      f[i][j] = 0;

  // 对所有分组进行排序
  for (int i = 1; i <= n; i++) {
    std::sort((Item *)group[i] + 1, (Item *)group[i] + 1 + group_n[i],
              ItemCompare);
  }

  // 第 k 组物品
  for (int k = 1; k <= n; k++) {
    // 一组中的第 i 个物品
    for (int i = 1; i <= group_n[k]; i++) {
      // 重量不超过 j
      for (int j = 0; j <= tot_weight; j++) {
        // 在同一组 k 中的不同物品 i 之间是互斥的
        // 至多只能选择一个
        // 选择物品 i 和前一个物品 i-1 之中价值最大的
        int tmp;
        if (j >= group[k][i].weight) {
          tmp = std::max(f[k - 1][j],
                         f[k - 1][j - group[k][i].weight] + group[k][i].value);
        } else {
          tmp = f[k - 1][j];
        }
        f[k][j] = std::max(f[k][j], tmp);
      }
    }
  }

  return f[n][tot_weight];
}

