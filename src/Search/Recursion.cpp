#pragma once
#include <vector>
#include <cstring>


/**
 * @brief Recursion 递归
 * @param s     所有成员的选择 s[i]表示成员i的选择
 * @param n     成员数量
 * @param m     选择数量
 * @param prev  上一个选择过的成员下标
 * @param comb  所有选择的集合
*/
void Recursion(std::vector<int> &tmp,
               const std::vector<int> &candidates,
               int prev,
               std::vector<std::vector<int>> &comb) {

  /* 递归终止条件 */
  if (prev == tmp.size()) {
    comb.push_back(tmp);
    return;
  }

  /* 遍历当前成员s[prev] 并递归进入下一个成员 */
  for (int i = 0; i < candidates.size(); ++i) {
    tmp[prev] = candidates[i];
    Recursion(tmp, candidates, prev + 1, comb);
  }
}
