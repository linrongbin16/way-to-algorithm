#pragma once
#ifndef MAX
#define MAX 64
#endif

struct LeftistTree;

struct LefNode {
  //节点下标
  int index;
  int distance;
  LefNode *left;
  LefNode *right;
  LeftistTree *tree;
};

struct LeftistTree {
  LefNode *root;
  int size;
  int (*cmp)(LefNode *, LefNode *);
};

// create leftist tree
LeftistTree *LeftistTreeNew(int (*Compare)(LefNode *a, LefNode *b));

// free leftist tree
void LeftistTreeFree(LeftistTree *t);

// merge two leftist tree
LeftistTree *LeftistTreeMerge(LeftistTree *a, LeftistTree *b);

// get top of leftist tree
int LeftistTreeTop(LeftistTree *t);

// push value to leftist tree
int LeftistTreePush(LeftistTree *t, int index);

// pop value from leftist tree
int LeftistTreePop(LeftistTree *t);

