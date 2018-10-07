#include "GroupBag.h"
#include "Util.h"
#include <algorithm>
#include <iostream>

static bool ItemCompare(const Item &a, const Item &b) {
  double rate_a = (double)a.v / (double)a.w;
  double rate_b = (double)b.v / (double)b.w;
  if (rate_a != rate_b)
    return rate_a > rate_b;
  else
    return a.w < b.w;
}

int GroupBag(Item group[MAX][MAX], int m, int n[MAX], int weight) {

  // f[k][j]表示前k组重量不超过j的最大价值

  int **f = Array2DNew(m + 1, weight + 1);
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= weight; j++)
      f[i][j] = 0;

  // 对所有分组进行排序

  for (int i = 1; i <= m; i++) {
    std::sort((Item *)group[i] + 1, (Item *)group[i] + 1 + n[i], ItemCompare);
  }

  // 第 k 组物品

  for (int k = 1; k <= m; k++) {

    // 一组中的第i个物品

    for (int i = 1; i <= n[k]; i++) {

      // 重量不超过j

      for (int j = 0; j <= weight; j++) {

        // 在同一组k中的不同物品i之间是互斥的
        // 至多只能选择一个
        // 选择物品i和前一个物品i-1之中价值最大的

        int tmp;
        if (j >= group[k][i].w) {
          tmp = std::max(f[k - 1][j],
                         f[k - 1][j - group[k][i].w] + group[k][i].v);
        } else {
          tmp = f[k - 1][j];
        }
        f[k][j] = std::max(f[k][j], tmp);
      }
    }
  }

  int result = f[m][weight];
  Array2DFree(f, m + 1);
  return result;
}

