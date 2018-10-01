#include "Recursion.h"
#include "Util.h"
#include <cstring>
#include <vector>

void Recursion(int *s, int n, int m, int prev,
               std::vector<std::vector<int>> &result) {
  // 递归终止条件
  if (prev == n) {
    result.push_back(BuildVector(s, 0, n));
    return;
  }

  // 遍历当前成员s[prev]
  // 递归进入下一个成员
  for (int i = 0; i < m; i++) {
    s[prev] = i;
    Recursion(s, n, m, prev + 1, result);
  }
}

