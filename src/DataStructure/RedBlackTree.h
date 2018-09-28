#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#define RED 'R'
#define BLACK 'B'

// TODO: bugs need fix

struct Node {
  /* 节点颜色 */
  char color;
  /* 节点值 */
  int index;
  Node *left;
  Node *right;
  Node *father;
};

struct RedBlackTree {
  Node *root;
};

RedBlackTree *RedBlackTreeNew();
void RedBlackTreeFree(RedBlackTree *t);
void RedBlackTreeInsert(RedBlackTree *t, int index);
int RedBlackTreeFind(RedBlackTree *t, int index);
void RedBlackTreeErase(RedBlackTree *t, int index);

