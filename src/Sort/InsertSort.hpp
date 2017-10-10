// Copyright 2017 zhaochenyou16@gmail.com

#ifndef SORT_INSERTSORT_HPP_
#define SORT_INSERTSORT_HPP_

#include <vector>
using namespace std;

/**
* @brief InsertSort 插入排序
* @param s[MAX]     无序序列
* @param beg        序列s的起始下标
* @param end        序列s为左闭右开区间[beg, end)
*/
auto InsertSort(vector<int> &s, int beg, int end) -> void {
  for (int j = beg+1; j < end; ++j) {
    int i;
    int p = s[j];
    /*s[0]到s[j]找到i，满足s[i-1]<=p<=s[i]*/
    /*注意i=beg时不存在s[i-1]的情况 */
    for (i = beg; i < j; ++i) {
      if (i == beg and p <= s[i])
        break;
      else if (i > beg and s[i-1] <= p and p <= s[i])
        break;
    }
    /*i即为p将被插入的位置*/
    /*将i到j-1之间的元素向右移动一位*/
    for (int k = j; k > i; --k)
      s[k] = s[k - 1];
    s[i] = p;
  }
}

#endif  // SRC_SORT_INSERTSORT_HPP_
