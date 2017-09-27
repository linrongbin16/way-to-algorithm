// Copyright 2017 zhaochenyou16@gmail.com

#ifndef SRC_SEARCH_BRUTEFORCE_HPP_
#define SRC_SEARCH_BRUTEFORCE_HPP_

#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


auto ArrayToVector(int s[MAX], int n) -> vector<int> {
    vector<int> ret;
    for (int i = 0; i < n; i++)
        ret.push_back(s[i]);
    return ret;
}

auto BruteForce(int s[MAX], int n, int m) -> vector<vector<int>> {
  vector<vector<int>> comb;
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
          comb.push_back(ArrayToVector(s, n));
        }

  return comb;
}


#endif  // SRC_SEARCH_BRUTEFORCE_HPP_
