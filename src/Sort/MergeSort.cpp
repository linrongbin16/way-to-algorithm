// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "MergeSort.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

#define TEST_MAX 1024
#define MAX 64

auto AssertNotAscendingOrder(const vector<int> &s,
                             int n) -> void {
  bool res = true;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      res = false;
      break;
    }
  }
  assert(!res);
}

auto AssertAscendingOrder(const vector<int> &s,
                          int n) -> void {
  bool res = true;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      res = false;
      break;
    }
  }
  assert(res);
}

auto AssertMergeSort(vector<int> &s,
                     int n) -> void {
  AssertNotAscendingOrder(s, n);
  MergeSort(s, 0, n);
  AssertAscendingOrder(s, n);
}


auto main(void) -> int {
  vector<int> s(MAX, 0);
  for (int i = 0; i < TEST_MAX; ++i) {
    for (int j = 0; j < MAX; ++j) {
      s[j] = rand() % TEST_MAX;
    }
    AssertMergeSort(s, MAX);
  }
  return 0;
}
