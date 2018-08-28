#include "FullPermutation.h"
#include <algorithm>
#include <cassert>
#include <vector>

static void FullPermutationImpl(std::vector<int> &A, int n, int prev,
                                std::vector<vector<int>> &result) {
  if (prev == 0) {
    result.push_back(A);
    return;
  }

  // 依次将A[prev]与它前面的prev-1个元素进行交换
  // i从prev开始 是为了产生一个初始化排列 该排列与A传入时完全一样
  for (int i = prev; i >= 0; i--) {
    std::swap(A[i], A[prev]);
    FullPermutationImpl(A, n, prev - 1, result);
    std::swap(A[i], A[prev]);
  }
}

std::vector<std::vector<int>> FullPermutation(int s[MAX], int n) {
  // 初始化 A=[s1, s2, s3, ..., sn]
  std::vector<int> A;
  for (int i = 0; i < n; i++)
    A.push_back(s[i]);
  std::vector<std::vector<int>> perm;
  FullPermutationImpl(A, n, n - 1, perm);

  return perm;
}

