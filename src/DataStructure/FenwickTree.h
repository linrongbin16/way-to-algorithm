#pragma once
#include <cstring>
#ifndef MAX
#define MAX 1024
#endif

struct FenwickTree {
  /*数组下标从1开始*/
  int bit[MAX];
};

FenwickTree *FenwickTreeNew();
FenwickTree *FenwickTreeNewFromArray(int *s);
void FenwickTreeFree(FenwickTree *t);
int FenwickTreeSum(FenwickTree *t, int i);

