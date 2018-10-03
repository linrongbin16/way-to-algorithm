#pragma once

#include <algorithm>
#include <cassert>

struct AvlNode {
  int value;
  int depth;
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
void AVLTreeInsert(AVLTree *t, int value);

// find AVLTree
int AVLTreeFind(AVLTree *t, int value);

// erase AVLTree
void AVLTreeErase(AVLTree *t, int value);

// AVLTree depth
int AVLTreeDepth(AVLTree *t);

