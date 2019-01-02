#pragma once
#include <algorithm>
#include <cassert>
#include <utility>

// TODO: bugs need fix

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

RedBlackTree *RedBlackTreeNew();
void RedBlackTreeFree(RedBlackTree *t);
void RedBlackTreeInsert(RedBlackTree *t, int value);
int RedBlackTreeFind(RedBlackTree *t, int value);
void RedBlackTreeErase(RedBlackTree *t, int value);

