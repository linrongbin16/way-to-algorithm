#pragma once
#ifndef MAX
#define MAX 1024
#endif

struct FwTree {
  int bits[MAX];
};

FwTree *FenwickTreeNew();
void FenwickTreeFree(FwTree *t);
void FenwickTreeAdd(FwTree *t, int i, int value);
int FenwickTreeSum(FwTree *t, int i, int j);

