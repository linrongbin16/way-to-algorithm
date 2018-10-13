#pragma once
#ifndef MAX
#define MAX 60
#endif

struct MtNode {
  int value;
  MtNode *child[MAX];
  int child_cnt;
};

int MaximumMultipleTree(MtNode *t, int n, int m);

