#pragma once
#include <vector>
#ifndef MAX
#define MAX 1024
#endif

/**
 * @brief Recursion 递归
 * @param s         所有成员的选择 s[i]表示成员i的选择
 * @param n         成员数量
 * @param m         每个成员的选择数量
 * @param prev      上一个选择过的成员下标
 * @param result    所有选择的集合
 */
void Recursion(int *s, int n, int m, int prev,
               std::vector<std::vector<int>> &result);

