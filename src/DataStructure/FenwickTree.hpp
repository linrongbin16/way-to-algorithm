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

FenwickTree *FenwickTreeNew();
FenwickTree *FenwickTreeNewFromArray(int *s);
void FenwickTreeFree(FenwickTree *t);
int FenwickTreeSum(FenwickTree *t, int i);


//
// implement
//

namespace detail {

  int LowBit(int i);

}

FenwickTree *FenwickTreeNew() {
  FenwickTree *t = new FenwickTree();
  if (!t) {
    return nullptr;
  }

  memset(t->bit, 0, MAX * sizeof(int));
  return t;
}

FenwickTree *FenwickTreeNewFromArray(int s[MAX]) {
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

void FenwickTreeFree(FenwickTree *t) {
  delete t;
}

void FenwickTreeAdd(FenwickTree *t, int i, int v) {
  for (int j = i; j < MAX; j += detail::LowBit(j)) {
    t->bit[j] += v;
  }
}

int FenwickTreeSum(FenwickTree *t, int i) {
  int sum = 0;
  for (int j = i; j > 0; j -= detail::LowBit(j)) {
    sum += t->bit[j];
  }
  return sum;
}

namespace detail {

  int LowBit(int i) {
    return i & (-i);
  }

}
