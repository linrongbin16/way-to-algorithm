// Copyright 2017 zhaochenyou16@gmail.com

#ifndef SRC_SORT_BUBBLESORT_HPP_
#define SRC_SORT_BUBBLESORT_HPP_

#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


/**
 * @brief BubbleSort 冒泡排序
 * @param s[MAX]    无序序列
 * @param beg       序列s的起始下标
 * @param end       序列s是左闭右开区间[beg, end)
 */

auto BubbleSort(
    vector<int> &s,
    int beg,
    int end) -> void {
  for (int i = end-1; i >= beg; --i)
    for (int j = beg; j < i; ++j)
      if (s[j] > s[j+1])
        swap(s[j], s[j+1]);
}


#endif  // SRC_SORT_BUBBLESORT_HPP_
