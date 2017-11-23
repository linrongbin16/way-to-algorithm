// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once
#include <cstring>

//
// interface
//

void MergeSort(int *s, int beg, int end);


// implement

namespace detail {

  void Merge(int *s, int start, int mid, int last);

}

/**
* @brief MergeSort  归并排序
* @param s[MAX]     无序序列
* @param beg        序列s的起始下标
* @param end        序列s为左闭右开区间[beg, end)
*/
void MergeSort(int *s, int beg, int end) {
  int mid = (beg + end-1) / 2;

  if (beg + 2 >= end) {
    detail::Merge(s, beg, mid, end-1);
    return;
  }
  MergeSort(s, beg, mid+1);
  MergeSort(s, mid+1, end);
  detail::Merge(s, beg, mid, end-1);
}

namespace detail {

  void Merge(int *s, int start, int mid, int last) {
    int *t = new int[last-start+2];
    int i, j, k;

    for (i = start, j = mid+1, k = start; i <= mid && j <= last; k++) {
      if (s[i] <= s[j]) {
        t[k] = s[i];
        i++;
      } else {
        t[k] = s[j];
        j++;
      }
    }
    for (; i <= mid; ++i, ++k)
      t[k] = s[i];
    for (; j <= last; ++j, ++k)
      t[k] = s[j];

    std::memcpy(s+start, t+start, (last-start)*sizeof(int));
    delete[] t;
  }

}

