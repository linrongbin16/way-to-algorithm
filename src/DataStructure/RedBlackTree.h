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

struct RedBlackTree {
  RbNode *root;
  RbNode NIL;
};

#define is_nil(t, e) ((e) == &(t->NIL))
#define not_nil(t, e) (!is_nil(t, e))
#define set_nil(t, e) ((e) = &(t->NIL))

RedBlackTree *RedBlackTreeNew();
void RedBlackTreeFree(RedBlackTree *t);
void RedBlackTreeInsert(RedBlackTree *t, int value);
RbNode *RedBlackTreeFind(RedBlackTree *t, int value);
void RedBlackTreeErase(RedBlackTree *t, int value);

