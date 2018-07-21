// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "quick_sort.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

#define TEST_MAX 1024
#define MAX 64

void assert_not_ascend(const int *s, int n) {
    bool res = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            res = false;
            break;
        }
    }
    assert(!res);
}

void assert_ascend(const int *s, int n) {
  bool res = true;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      res = false;
      break;
    }
  }
  assert(res);
}

void assert_quick_sort(int *s, int n) {
    assert_not_ascend(s, n);
    quick_sort(s, 0, n);
    assert_ascend(s, n);
}

int main(void) {
    int s[MAX];
    for (int i = 0; i < TEST_MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            s[j] = rand() % TEST_MAX;
        }
        assert_quick_sort(s, MAX);
    }
    return 0;
}

