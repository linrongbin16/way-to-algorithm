// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <vector>
#include <algorithm>
using namespace std;


// 序列a和b的范围是[1,n]
auto LongestCommonSubsequence(const int a[MAX],
                             const int b[MAX],
                             int n) -> int {
  int f[MAX][MAX];

  // 初始化
  for (int i = 0; i < MAX; i++) {
    f[i][0] = 0;
    f[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i] == b[j])
        f[i][j] = f[i-1][j-1] + 1;
      else
        f[i][j] = max( f[i-1][j], f[i][j-1] );
    }
  }

  return f[n][n];
}
