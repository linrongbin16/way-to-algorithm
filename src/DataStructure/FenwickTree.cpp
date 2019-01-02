#include "FenwickTree.h"
#include <cassert>
#include <cstring>

static int LowBit(int x) { return x & (-x); }

FwTree *FenwickTreeNew() {
  FwTree *t = new FwTree();
  memset(t->bits, 0, MAX * sizeof(int));
  return t;
}

void FenwickTreeFree(FwTree *t) { delete t; }

void FenwickTreeAdd(FwTree *t, int i, int value) {
  assert(i > 0);
  for (int j = i; j < MAX; j += LowBit(j)) {
    t->bits[j] += value;
  }
}

static int PrefixSum(FwTree *t, int n) {
  int sum = 0;
  for (int j = n; j > 0; j -= LowBit(j)) {
    sum += t->bits[j];
  }
  return sum;
}

int FenwickTreeSum(FwTree *t, int i, int j) {
  assert(i > 0);
  assert(j > i);
  int p = PrefixSum(t, i - 1);
  int q = PrefixSum(t, j - 1);
  return q - p;
}

