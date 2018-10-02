#include "LeftistTree.h"
#include <algorithm>

static LefNode *Merge(LefNode *a, LefNode *b, LeftistTree *t) {
  if (!a && !b)
    return NULL;
  if (!a) {
    b->tree = t;
    return b;
  }
  if (!b) {
    a->tree = t;
    return a;
  }

  if (t->cmp(a, b) > 0) {
    return Merge(b, a, t);
  }

  a->right = Merge(a->right, b, t);
  a->right->tree = t;

  if (!a->left) {
    std::swap(a->left, a->right);
  } else {
    if (a->left->distance < a->right->distance)
      std::swap(a->left, a->right);
    a->distance = a->right->distance + 1;
  }

  return a;
}

static void LefNodeFree(LefNode *e) {
  if (!e)
    return;
  LefNodeFree(e->left);
  LefNodeFree(e->right);
  delete e;
}

LeftistTree *LeftistTreeNew(int (*Compare)(LefNode *a, LefNode *b)) {
  LeftistTree *t = new LeftistTree();
  t->cmp = Compare;
  t->root = NULL;
  t->size = 0;
  return t;
}

void LeftistTreeFree(LeftistTree *t) {
  LefNodeFree(t->root);
  delete t;
}

LeftistTree *LeftistTreeMerge(LeftistTree *a, LeftistTree *b) {
  LeftistTree *t = new LeftistTree();
  if (!t)
    return NULL;
  t->cmp = a->cmp;
  t->size = a->size + b->size;
  t->root = Merge(a->root, b->root, a);
  return t;
}

int LeftistTreeTop(LeftistTree *t) { return t->root ? t->root->index : -1; }

int LeftistTreePush(LeftistTree *t, int index) {
  LefNode *e = new LefNode();
  if (!e)
    return -1;
  e->distance = 0;
  e->index = index;
  e->left = NULL;
  e->right = NULL;
  e->tree = NULL;

  t->root = Merge(t->root, e, t);
  t->size += 1;

  return 0;
}

int LeftistTreePop(LeftistTree *t) {
  if (t->size <= 0)
    return -1;

  LefNode *old = t->root;
  t->root = Merge(t->root->left, t->root->right, t);
  t->size -= 1;
  delete old;

  return 0;
}

