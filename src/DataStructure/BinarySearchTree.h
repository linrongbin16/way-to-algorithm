#pragma once
#include <vector>

struct BsNode {
  int value;
  BsNode *left;
  BsNode *right;
  BsNode *father;

  BsNode();
  BsNode(int v, BsNode *l, BsNode *r, BsNode *f);
};

extern BsNode BSNIL;

struct BinarySearchTree {
  BsNode *root;
};

// create binary search tree
BinarySearchTree *BinarySearchTreeNew();

// free binary search tree
void BinarySearchTreeFree(BinarySearchTree *t);

// insert value to binary search tree
void BinarySearchTreeInsert(BinarySearchTree *t, int value);

// find value from binary search tree
BsNode *BinarySearchTreeFind(BinarySearchTree *t, int value);

// find value from binary search tree
void BinarySearchTreeErase(BinarySearchTree *t, int value);

// pre order
std::vector<int> BinarySearchTreePreOrder(BinarySearchTree *t);
// post order
std::vector<int> BinarySearchTreePostOrder(BinarySearchTree *t);
// in order
std::vector<int> BinarySearchTreeInOrder(BinarySearchTree *t);
// level order
std::vector<int> BinarySearchTreeLevelOrder(BinarySearchTree *t);

