#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#define RED 'R'
#define BLACK 'B'

// TODO: bugs need fix

struct RbNode {
  /* 节点颜色 */
  char color;
  /* 节点值 */
  int index;
  RbNode *left;
  RbNode *right;
  RbNode *father;
};

struct RedBlackTree {
  RbNode *root;
};

RedBlackTree *RedBlackTreeNew();
void RedBlackTreeFree(RedBlackTree *t);
void RedBlackTreeInsert(RedBlackTree *t, int index);
int RedBlackTreeFind(RedBlackTree *t, int index);
void RedBlackTreeErase(RedBlackTree *t, int index);

