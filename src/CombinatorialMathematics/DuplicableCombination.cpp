#include "Recursion.h"
#include <algorithm>
#include <vector>
using namespace std;

void Recursion(vector<int> &tmp, const vector<int> &candidates, int prev,
               vector<vector<int>> &comb) {
  /* 递归终止条件 */
  if (prev == tmp.size()) {
    comb.push_back(tmp);
    return;
  }

  /* 遍历当前成员s[prev] 并递归进入下一个成员 */
  for (int i = 0; i < candidates.size(); i++) {
    tmp[prev] = candidates[i];
    Recursion(tmp, candidates, prev + 1, comb);
  }
}

vector<vector<int>> DuplicableCombination(vector<int> &candidates, int n) {
  vector<vector<int>> comb;
  vector<int> tmp(n, 0);
  Recursion(tmp, candidates, 0, comb);
  return comb;
}

