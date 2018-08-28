#include "Recursion.h"
#include "Util.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

#define TEST_N_MAX 8
#define TEST_M_MAX 8

int main() {
  for (int i = 1; i < TEST_N_MAX; i++)
    for (int j = 1; j < TEST_M_MAX; j++) {
      vector<int> tmp(i, 0);
      vector<vector<int>> result;
      vector<int> candidates(j, 0);
      for (int k = 0; k < j; k++)
        candidates[k] = k;
      Recursion(tmp, candidates, 0, result);
      assert((double)result.size() == std::pow<double>(j, i));
      AssertUnique(result);
    }
  return 0;
}
