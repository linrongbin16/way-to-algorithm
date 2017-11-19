// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;


auto LongestIncreasingSubsequence(const int s[MAX],
                                  int n) -> int {
  // 序列a和b的范围是[1,n]
  int f[MAX];

  // 初始化
  f[0] = 0;

  for (int i = 1; i <= n; i++) {
    f[i] = 1;
    int max_length = 0;
    for (int k = 1; k < i; k++) {
      if (s[i] > s[k])
        max_length = max(max_length, f[k]);
    }
    f[i] = max_length+1;
  }

  int list = 1;
  for (int i = 1; i <= n; i++) {
    list = max(list, f[i]);
  }

  return list;
}
