#pragma once
#ifndef MAX
#define MAX 1024
#endif

struct BiNode {
  int index;
  int value;
  BiNode *left;
  BiNode *right;
};

BiNode *MaxBinaryTreeNew(int *value, int *left, int *right, int n);

void MaxBinaryTreeFree(BiNode *t);

int MaxBinaryTree(BiNode *t, int n, int m);

