#pragma once
#ifndef MAX
#define MAX 64
#endif

struct LeftistTree;

struct LtNode {
  //节点下标
  int index;
  int distance;
  LtNode *left;
  LtNode *right;
  LeftistTree *tree;
};

struct LeftistTree {
  LtNode *root;
  int size;
  int (*cmp)(LtNode *, LtNode *);
};

// create leftist tree
LeftistTree *LeftistTreeNew(int (*Compare)(LtNode *a, LtNode *b));

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

