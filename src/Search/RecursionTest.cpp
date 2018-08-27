#include "Recursion.h"
#include <cmath>
#include <cassert>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

#define TEST_N_MAX 8
#define TEST_M_MAX 8


auto main() -> int {
  for (int i = 1; i < TEST_N_MAX; i++)
    for (int j = 1; j < TEST_M_MAX; j++) {
      vector<int> tmp(i, 0);
      vector<vector<int>> result;
      vector<int> candidates(j, 0);
      for (int k = 0; k < j; k++) candidates[k] = k;
      Recursion(tmp, candidates, 0, result);
      assert( (double)result.size() == std::pow<double>(j, i) );
      AssertUnique(result);
    }
  return 0;
}
