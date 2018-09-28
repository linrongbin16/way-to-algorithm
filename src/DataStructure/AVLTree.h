#pragma once

#include <algorithm>
#include <cassert>

struct AvlNode {
  /*节点下标号*/
  int index;
  /*节点高度值*/
  int depth;
  /*左右孩子节点*/
  AvlNode *left;
  AvlNode *right;
};

struct AVLTree {
  AvlNode *root;
};

// create AVLTree
AVLTree *AVLTreeNew();

// free AVL Tree
void AVLTreeFree(AVLTree *t);

// insert into AVLTree
void AVLTreeInsert(AVLTree *t, int index);

// find AVLTree
int AVLTreeFind(AVLTree *t, int index);

// erase AVLTree
void AVLTreeErase(AVLTree *t, int index);

// AVLTree depth
int AVLTreeDepth(AVLTree *t);

