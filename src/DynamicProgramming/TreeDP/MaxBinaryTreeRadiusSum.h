#pragma once
#ifndef MAX
#define MAX 1024
#endif

struct BrsNode {
  int index;
  int value;
  BrsNode *left;
  BrsNode *right;
  BrsNode *father;
};

BrsNode *MaxBinaryTreeRadiusSumNew(int *value, int *left, int *right, int n);

void MaxBinaryTreeRadiusSumFree(BrsNode *t);

int MaxBinaryTreeRadiusSum(BrsNode *t);

