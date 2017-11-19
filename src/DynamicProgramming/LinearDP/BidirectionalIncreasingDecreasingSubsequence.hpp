// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;


//
// interface
//
auto BidirectionalIncreasingDecreasingSubsequence(const int s[MAX], int n) -> int;


//
// implement
//

namespace detail {

  auto LongestIncreasingSubsequence(int f[MAX],
                                    int g[MAX],
                                    const int s[MAX],
                                    int n) -> void;

  auto LongestDecreasingSubsequence(int f[MAX],
                                    int g[MAX],
                                    const int s[MAX],
                                    int n) -> void;
}

auto BidirectionalIncreasingDecreasingSubsequence(const int s[MAX], int n) -> int {
  int f[MAX], g[MAX];
  detail::LongestIncreasingSubsequence(f, g, s, n);
  detail::LongestDecreasingSubsequence(f, g, s, n);

  int bimax = 0;
  for (int i = 1; i <= n; i++) {
    bimax = max(f[i]+g[i]-1, bimax);
  }

  return bimax;
}

namespace detail {

  auto LongestIncreasingSubsequence(int f[MAX],
                                    int g[MAX],
                                    const int s[MAX],
                                    int n) -> void {
    // 初始化
    f[0] = 0;
    for (int i = 1; i <= n; i++)
      f[i] = 1;

    for (int i = 1; i <= n; i++) {
      int max_length = 0;
      for (int k = 1; k < i; k++) {
        if (s[i] > s[k])
          max_length = max(max_length, f[k]);
      }
      f[i] = max_length+1;
    }
  }

  auto LongestDecreasingSubsequence(int f[MAX],
                                    int g[MAX],
                                    const int s[MAX],
                                    int n) -> void {
    // 初始化
    g[0] = 0;
    for (int i = n; i >= 1; i--)
      g[i] = 1;

    for (int i = n; i >= 1; i--) {
      int max_length = 0;
      for (int k = n; k > i; k--) {
        if (s[i] > s[k])
          max_length = max(max_length, g[k]);
      }
      g[i] = max_length+1;
    }
  }

}

