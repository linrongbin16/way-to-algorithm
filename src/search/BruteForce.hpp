// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#include <vector>
#include <cstring>
#ifndef MAX
#define MAX 1024
#endif

//
// interface
//

std::vector<std::vector<int>> BruteForce(int s[MAX], int n, int m);


//
// implement
//

namespace detail {

  std::vector<int> ArrayToVector(int *s, int n);

}

std::vector<std::vector<int>> BruteForce(int s[MAX], int n, int m) {
  std::vector<std::vector<int>> comb;
  for (int i_0 = 0; i_0 < m; i_0++)
    for (int i_1 = 0; i_1 < m; i_1++)
      for (int i_2 = 0; i_2 < m; i_2++)
        /* ... */
        for (int i_n_1 = 0; i_n_1 < m; i_n_1++) {
          s[0] = i_0;
          s[1] = i_1;
          s[2] = i_2;
          /* ... */
          s[n - 1] = i_n_1;
          comb.push_back(detail::ArrayToVector(s, n));
        }
  return comb;
}

namespace detail {

  std::vector<int> ArrayToVector(int *s, int n) {
    std::vector<int> ret;
    for (int i = 0; i < n; i++)
      ret.push_back(s[i]);
    return ret;
  }

}
