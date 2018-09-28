#include "Recursion.h"
#include "Util.h"
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

#define TEST_N_MAX 8
#define TEST_M_MAX 8

int main() {
  int s[MAX];

  for (int i = 1; i < TEST_N_MAX; i++)
    for (int j = 1; j < TEST_M_MAX; j++) {
      std::memset(s, 0, sizeof(int) * MAX);
      vector<vector<int>> result;
      Recursion(s, i, j, 0, result);
      assert(result.size() == (int)std::pow<double>(j, i));
      AssertUnique(result);
    }
  return 0;
}

