// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#include <cstring>
#ifndef MAX
#define MAX 1024
#endif


//
// interface
//

struct FenwickTree {
  /*数组下标从1开始*/
  int bit[MAX];
};

auto FenwickTreeNew() -> FenwickTree*;
auto FenwickTreeNewFromArray(int s[MAX]) -> FenwickTree*;
auto FenwickTreeFree(FenwickTree *t) -> void;
auto FenwickTreeSum(FenwickTree *t, int i) -> int;


//
// implement
//

namespace detail {

  auto LowBit(int i) -> int;

}

auto FenwickTreeNew() -> FenwickTree* {
  FenwickTree *t = new FenwickTree();
  if (!t) {
    return nullptr;
  }

  memset(t->bit, 0, MAX * sizeof(int));
  return t;
}

auto FenwickTreeNewFromArray(int s[MAX]) -> FenwickTree* {
  FenwickTree *t = new FenwickTree();
  if (!t) {
    return nullptr;
  }

  memset(t->bit, 0, MAX * sizeof(int));
  /* 数组下标从1开始 */
  for (int i = 1; i < MAX; i++) {
    t->bit[i] = s[i];
    for (int j = i-1; j > i - detail::LowBit(i); j--)
      t->bit[i] += s[i];
  }

  return t;
}

auto FenwickTreeFree(FenwickTree *t) -> void {
  delete t;
}

auto FenwickTreeAdd(FenwickTree *t, int i, int v) -> void {
  for (int j = i; j < MAX; j += detail::LowBit(j)) {
    t->bit[j] += v;
  }
}

auto FenwickTreeSum(FenwickTree *t, int i) -> int {
  int sum = 0;
  for (int j = i; j > 0; j -= detail::LowBit(j)) {
    sum += t->bit[j];
  }
  return sum;
}

namespace detail {

  auto LowBit(int i) -> int {
    return i & (-i);
  }

}
