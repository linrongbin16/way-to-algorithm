#pragma once

struct AvlNode {
  int value;
  int height;
  AvlNode *left;
  AvlNode *right;

  AvlNode();
  AvlNode(int v, int h, AvlNode *l, AvlNode *r);
};

extern AvlNode AVLNIL;

struct AvlTree {
  AvlNode *root;
};

#define is_nil(e) ((e) == &AVLNIL)
#define not_nil(e) ((e) != &AVLNIL)
#define set_nil(e) ((e) = &AVLNIL)

// create AvlTree
AvlTree *AvlTreeNew();

// free AVL Tree
void AvlTreeFree(AvlTree *t);

// insert into AvlTree
void AvlTreeInsert(AvlTree *t, int value);

// find value node
AvlNode *AvlTreeFind(AvlTree *t, int value);

// erase AvlTree
void AvlTreeErase(AvlTree *t, int value);

// AvlTree height
int AvlTreeHeight(AvlTree *t);

