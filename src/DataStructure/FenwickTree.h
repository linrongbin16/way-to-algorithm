#pragma once
#ifndef MAX
#define MAX 1024
#endif

struct FenTree {
  int bits[MAX];
};

FenTree *FenwickTreeNew();
void FenwickTreeFree(FenTree *t);
void FenwickTreeAdd(FenTree *t, int i, int value);
int FenwickTreeSum(FenTree *t, int i, int j);

