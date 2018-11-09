#pragma once
#ifndef MAX
#define MAX 1024
#endif
#ifndef CHILD_MAX
#define CHILD_MAX 64
#endif

struct MtNode {
  int index;
  int value;
  MtNode *child[CHILD_MAX];
  int child_cnt;
};

MtNode *MaximumMultipleTreeNew(int *value, int *father, int n);
void MaximumMultipleTreeFree(MtNode *t);

int MaximumMultipleTree(MtNode *t, int n, int m);

