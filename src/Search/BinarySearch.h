#pragma once
#include <utility>

/**
 * 在升序序列s中找出x的位置（下标）
 * @params s            升序序列
 * @params beg          序列s的起始下标
 * @params end          序列s的末尾下标加1，即左闭右开区间[beg, end)
 * @params index        返回找到的x下标
 * @return              找到x返回true 否则返回false
 */
std::pair<bool, int> BinarySearch(const int* s, int beg, int end, int x);
