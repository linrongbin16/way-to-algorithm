// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP 1

#include <vector>
#include <algorithm>
using namespace std;


/**
 * @brief Partion 
 * 以s[low]为中间值，将所有小于等于s[low]的放在左边，
 * 大于等于[low]的放在右边
 *
 * @param s[MAX]    无序序列
 * @param low       序列s的起始下标
 * @param high      序列s的末尾下标，即左闭右闭区间[low, high]
 * @return          最终s[low]所在下标
 */
auto Partion(vector<int> &s, int low, int high) -> int {
  int p = s[low];
  while (low < high) {
    while (low < high and s[high] >= p)
      --high;
    s[low] = s[high];
    while (low < high and s[low] <= p)
      ++low;
    s[high] = s[low];
  }
  s[low] = p;
  return low;
}

/**
 * @brief QuickSort
 * @param s[MAX]    无序序列
 * @param beg       序列s的起始下标
 * @param end       序列s的末尾下标加1，即左闭右开区间[beg, end)
 */
auto QuickSort(vector<int> &s, int beg, int end) -> void {
  if (beg < end-1) {
    int mid = Partion(s, beg, end-1);
    QuickSort(s, beg, mid);
    QuickSort(s, mid+1, end);
  }
}


#endif  // QUICK_SORT_HPP
