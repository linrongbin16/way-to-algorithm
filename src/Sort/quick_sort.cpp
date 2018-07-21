// MIT License
// Copyright 2018 linrongbin16@gmail.com
#include "quick_sort.h"


/**
 * detail methods
 */
namespace detail {
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
    int partion(int *s, int low, int high);
}


/**
 * @brief QuickSort
 * @param s[MAX]    无序序列
 * @param beg       序列s的起始下标
 * @param end       序列s的末尾下标加1，即左闭右开区间[beg, end)
 */
void quick_sort(int *s, int beg, int end) {
    if (beg < end-1) {
        int mid = detail::partion(s, beg, end-1);
        quick_sort(s, beg, mid);
        quick_sort(s, mid+1, end);
    }
}

namespace detail {
    int partion(int *s, int low, int high) {
        int p = s[low];
        while (low < high) {
            while (low < high && s[high] >= p)
                --high;
            s[low] = s[high];
            while (low < high && s[low] <= p)
                ++low;
            s[high] = s[low];
        }
        s[low] = p;
        return low;
    }
}// namespace detail
// 
// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "QuickSort.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

#define TEST_MAX 1024
#define MAX 64

void AssertNotAscendingOrder(int *s, int n) {
  bool res = true;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      res = false;
      break;
    }
  }
  assert(!res);
}

void AssertAscendingOrder(int *s, int n) {
  bool res = true;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      res = false;
      break;
    }
  }
  assert(res);
}

void AssertQuickSort(int *s, int n) {
  AssertNotAscendingOrder(s, n);
  QuickSort(s, 0, n);
  AssertAscendingOrder(s, n);
}


auto main(void) -> int {
  int s[MAX];
  for (int i = 0; i < TEST_MAX; ++i) {
    for (int j = 0; j < MAX; ++j) {
      s[j] = rand() % TEST_MAX;
    }
    AssertQuickSort(s, MAX);
  }
  return 0;
}

