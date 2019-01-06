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
};

extern RbNode RBNIL;

#define is_nil(e) ((e) == &RBNIL)
#define not_nil(e) ((e) != &RBNIL)
#define set_nil(e) ((e) = &RBNIL)

RedBlackTree *RedBlackTreeNew();
void RedBlackTreeFree(RedBlackTree *t);
void RedBlackTreeInsert(RedBlackTree *t, int value);
RbNode *RedBlackTreeFind(RedBlackTree *t, int value);
void RedBlackTreeErase(RedBlackTree *t, int value);

