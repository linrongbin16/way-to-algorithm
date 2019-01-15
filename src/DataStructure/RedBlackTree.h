#pragma once
#include <algorithm>
#include <cassert>
#include <utility>

struct RbNode {
  char color;
  int value;
  RbNode *left;
  RbNode *right;
  RbNode *father;
};

struct RbTree {
  RbNode *root;
  RbNode NIL;
};

#define is_nil(t, e) ((e) == &((t)->NIL))
#define not_nil(t, e) (!is_nil(t, e))
#define set_nil(t, e) ((e) = &((t)->NIL))

RbTree *RedBlackTreeNew();
void RedBlackTreeFree(RbTree *t);
void RedBlackTreeInsert(RbTree *t, int value);
RbNode *RedBlackTreeFind(RbTree *t, int value);
void RedBlackTreeErase(RbTree *t, int value);

