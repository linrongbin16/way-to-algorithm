#pragma once

struct AvlNode {
  int value;
  int height;
  AvlNode *left;
  AvlNode *right;
  AvlNode *father;

  AvlNode();
  AvlNode(int v, int h, AvlNode *l, AvlNode *r, AvlNode *f);
};

extern AvlNode AVLNIL;

struct AvlTree {
  AvlNode *root;
};

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

