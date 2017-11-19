// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <vector>
#include <algorithm>
using namespace std;


// 前 i 个物品重量不超过 j 的最大价值

int ZeroOneKnapsack(int value[MAX],
                    int weight[MAX],
                    int count,
                    int total_weight) {

  int f[MAX][MAX];

  // 初始化
  for (int i = 0; i < MAX; i++) {
    f[0][i] = 0;
    f[i][0] = 0;
  }

  // 第 i 个物品
  for (int i = 1; i <= count; i++) {
    // 重量不超过 j
    for (int j = 0; j <= total_weight; j++) {
      if (j >= weight[i])
        f[i][j] = max( f[i-1][j], f[i-1][j-weight[i]] + value[i]);
      else
        f[i][j] = f[i-1][j];
    }
  }

  return f[count][total_weight];
}
