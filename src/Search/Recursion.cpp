#include "Recursion.h"
#include "Util.h"
#include <cstring>
#include <vector>

void Recursion(int *s, int n, int m, int prev,
               std::vector<std::vector<int>> &result) {
  // 递归终止条件
  if (prev == n) {
    result.push_back(IntArrayToVector(s, n));
    return;
  }

  // 遍历当前成员s[prev]
  // 递归进入下一个成员
  for (int i = 0; i < n; i++) {
    s[prev] = s[i];
    Recursion(s, n, m, prev + 1, result);
  }
}

