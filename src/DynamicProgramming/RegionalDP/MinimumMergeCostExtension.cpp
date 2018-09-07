#include "MinimumMergeCostExtension.h"
#include <algorithm>
#include <climits>
#include <iostream>

int MinimumMergeCostExtension(int *s, int n) {
  //序列s的数量为n 范围是[1,n] 返回最小合并代价
  int f[MAX + 1][MAX + 1];
  int sum[MAX + 1][MAX + 1];
  //对于1<=i<=n f[i][i]=0 sum[i][i]=0
  //而对于1<=i!=j<=n f[i][j]=INF
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      //初始化
      f[i][j] = (i == j) ? 0 : INF;
      sum[i][j] = 0;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = i; k <= j; ++k)
        // sum[i][j]存储序列i到j的元素之和
        sum[i][j] += s[k];
  // i范围是[1,n]
  for (int i = 1; i <= n; ++i)
    // j范围是[i+1,n]
    for (int j = i + 1; j <= n; ++j)
      for (int k = i; k < j; ++k) {
        if (f[i][k] == INF or f[k + 1][j] == INF)
          continue;
        f[i][j] = std::min(f[i][j],
                           f[i][k] + f[k + 1][j] + sum[i][k] + sum[k + 1][j]);
      }

  return f[1][n];
}

