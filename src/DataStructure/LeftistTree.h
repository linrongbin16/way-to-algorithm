#pragma once
#include <algorithm>
#ifndef MAX
#define MAX 64
#endif

struct LeftistTree;

struct Node {
    //节点下标
    int index;
    int distance;
    Node *left;
    Node *right;
    LeftistTree *tree;
};

struct LeftistTree {
    Node *root;
    int size;
    int (*cmp)(Node *, Node *);
};

// create leftist tree
LeftistTree *LeftistTreeNew(int (*Compare)(Node *a, Node *b));

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
