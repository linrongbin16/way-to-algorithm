// MIT License
// Copyright 2017- linrongbin16@gmail.com

#pragma once
#include <vector>

/**
 * @brief Recursion 递归
 * @param s         所有成员的选择 s[i]表示成员i的选择
 * @param n         成员数量
 * @param m         选择数量
 * @param prev      上一个选择过的成员下标
 * @param result    所有选择的集合
*/
void Recursion(std::vector<int> &tmp,
               const int *s,
               int n,
               int m,
               int prev,
               std::vector<std::vector<int>> &result);
