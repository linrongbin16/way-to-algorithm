// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>


//
// interface
//

int BidirectionalIncreasingDecreasingSubsequence(const int *s, int n);


//
// implement
//

namespace detail {

  void LongestIncreasingSubsequence(int *f,
                                    int *g,
                                    const int *s,
                                    int n);

  void LongestDecreasingSubsequence(int *f,
                                    int *g,
                                    const int *s,
                                    int n);
}

int BidirectionalIncreasingDecreasingSubsequence(const int *s, int n) {
  int f[MAX], g[MAX];
  detail::LongestIncreasingSubsequence(f, g, s, n);
  detail::LongestDecreasingSubsequence(f, g, s, n);

  int bimax = 0;
  for (int i = 1; i <= n; i++) {
    bimax = std::max(f[i]+g[i]-1, bimax);
  }

  return bimax;
}

namespace detail {

  void LongestIncreasingSubsequence(int *f,
                                    int *g,
                                    const int *s,
                                    int n) {
    // 初始化
    f[0] = 0;
    for (int i = 1; i <= n; i++)
      f[i] = 1;

    for (int i = 1; i <= n; i++) {
      int max_length = 0;
      for (int k = 1; k < i; k++) {
        if (s[i] > s[k])
          max_length = std::max(max_length, f[k]);
      }
      f[i] = max_length+1;
    }
  }

  void LongestDecreasingSubsequence(int *f,
                                    int *g,
                                    const int *s,
                                    int n) {
    // 初始化
    g[0] = 0;
    for (int i = n; i >= 1; i--)
      g[i] = 1;

    for (int i = n; i >= 1; i--) {
      int max_length = 0;
      for (int k = n; k > i; k--) {
        if (s[i] > s[k])
          max_length = std::max(max_length, g[k]);
      }
      g[i] = max_length+1;
    }
  }

}

