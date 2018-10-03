#include "FenwickTree.h"
#include <cassert>
#include <cstring>

static int LowBit(int x) { return x & (-x); }

FenTree *FenwickTreeNew() {
  FenTree *t = new FenTree();
  memset(t->bits, 0, MAX * sizeof(int));
  return t;
}

void FenwickTreeFree(FenTree *t) { delete t; }

void FenwickTreeAdd(FenTree *t, int i, int value) {
  assert(i > 0);
  for (int j = i; j < MAX; j += LowBit(j)) {
    t->bits[j] += value;
  }
}

static int PrefixSum(FenTree *t, int n) {
  int sum = 0;
  for (int j = n; j > 0; j -= LowBit(j)) {
    sum += t->bits[j];
  }
  return sum;
}

int FenwickTreeSum(FenTree *t, int i, int j) {
  assert(i > 0);
  assert(j > i);
  int p = PrefixSum(t, i - 1);
  int q = PrefixSum(t, j - 1);
  return q - p;
}

