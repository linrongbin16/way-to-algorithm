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

