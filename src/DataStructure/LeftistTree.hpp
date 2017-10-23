// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#ifndef DATASTRUCTURE_LEFTISTTREE_HPP
#define DATASTRUCTURE_LEFTISTTREE_HPP

#include <algorithm>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

struct LeftistTree;

struct LeftistNode {
  //节点下标
  int index;
  int distance;
  LeftistNode *left;
  LeftistNode *right;
  LeftistTree *tree;
};

struct LeftistTree {
  LeftistNode *root;
  int size;
  int (*cmp)(LeftistNode*, LeftistNode*);
};

auto LeftistTreeNew(int (*Compare)(LeftistNode *a, LeftistNode *b)) -> LeftistTree* {
  LeftistTree *t = new LeftistTree();
  if (!t) return nullptr;
  t->cmp = Compare;
  t->root = nullptr;
  t->size = 0;
  return t;
}

auto NodeFree(LeftistNode *e) -> void {
  if (!e) return;
  NodeFree(e->left);
  NodeFree(e->right);
  delete e;
}

auto LeftistTreeFree(LeftistTree *t) -> void {
  NodeFree(t->root);
  delete t;
}

auto NodeMerge(LeftistNode *a, LeftistNode *b, LeftistTree *t) -> LeftistNode* {
  if (!a and !b)
    return nullptr;
  if (!a) {
    b->tree = t;
    return b;
  }
  if (!b) {
    a->tree = t;
    return a;
  }

  if (t->cmp(a, b) > 0) {
    return NodeMerge(b, a, t);
  }

  a->right = NodeMerge(a->right, b, t);
  a->right->tree = t;

  if (!a->left) {
    swap(a->left, a->right);
  } else {
    if (a->left->distance < a->right->distance)
      swap(a->left, a->right);
    a->distance = a->right->distance + 1;
  }

  return a;
}

auto LeftistTreeMerge(LeftistTree *a, LeftistTree *b) -> LeftistTree* {
  LeftistTree *t = new LeftistTree();
  if (!t)
    return nullptr;
  t->cmp = a->cmp;
  t->size = a->size + b->size;
  t->root = NodeMerge(a->root, b->root, a);
  return t;
}

auto LeftistTreeTop(LeftistTree *t) -> int {
  return t->root ? t->root->index : -1;
}

auto LeftistTreePush(LeftistTree *t, int index) -> int {
  LeftistNode *e = new LeftistNode();
  if (!e)
    return -1;
  e->distance = 0;
  e->index = index;
  e->left = nullptr;
  e->right = nullptr;
  e->tree = nullptr;

  t->root = NodeMerge(t->root, e, t);
  t->size += 1;

  return 0;
}

auto LeftistTreePop(LeftistTree *t) -> int {
  if (t->size <= 0)
    return -1;

  LeftistNode *old = t->root;
  t->root = NodeMerge(t->root->left, t->root->right, t);
  t->size -= 1;
  delete old;

  return 0;
}


#endif // DATASTRUCTURE_LEFTISTTREE_HPP
