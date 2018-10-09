#include "MinimumMergeCost.h"
#include "../Util.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

// 防止int溢出

static int InfAdd(int a, int b) {
  if (a == INF || b == INF)
    return INF;
  return a + b;
}

static int InfAdd(int a, int b, int c) {
  if (a == INF || b == INF || c == INF)
    return INF;
  return a + b + c;
}

int MinimumMergeCost(int *s, int n) {
  int **f = Array2DNew(n + 1, n + 1);
  int **sum = Array2DNew(n + 1, n + 1);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      f[i][j] = (i == j) ? 0 : INF;
      sum[i][j] = 0;
    }

  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      for (int k = i; k <= j; k++)
        sum[i][j] += s[k];

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = i; k < j; k++) {
        f[i][j] = std::min(f[i][j], InfAdd(InfAdd(f[i][k], f[k + 1][j]),
                                           sum[i][k], sum[k + 1][j]));
      }

  int result = f[1][n];
  Array2DFree(f, n + 1);
  Array2DFree(sum, n + 1);
  return result;
}

