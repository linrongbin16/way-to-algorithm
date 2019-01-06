#pragma once
#include <vector>

struct BsNode {
  int value;
  BsNode *left;
  BsNode *right;

  BsNode();
  BsNode(int v, BsNode *l, BsNode *r);
};

struct BinarySearchTree {
  BsNode *root;
};

extern BsNode BSNIL;

#define is_nil(e) ((e) == &BSNIL)
#define not_nil(e) ((e) != &BSNIL)
#define set_nil(e) ((e) = &BSNIL)

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

