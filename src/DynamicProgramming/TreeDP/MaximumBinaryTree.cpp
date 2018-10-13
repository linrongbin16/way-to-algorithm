#include "MaximumBinaryTree.h"
#include "../Util.h"
#include <algorithm>
#include <cassert>
#include <cstddef>

BiNode::BiNode() {
  index = 0;
  value = 0;
  left = NULL;
  right = NULL;
}

BiNode::BiNode(int i, int v, BiNode *l, BiNode *r) {
  index = i;
  value = v;
  left = l;
  right = r;
}

static BiNode *Insert(BiNode *e, int index, int value, int *left, int *right) {
  if (e == NULL) {
    e = new BiNode(index, value, NULL, NULL);
    return e;
  }
}

BiNode *MaximumBinaryTreeNew(int *v, int *left, int *right, int n) {
  BiNode *root;
  return root;
}

void MaximumBinaryTreeFree(BiNode *t) { assert(t); }

static int MaximumBinaryTreeRec(MbTree *t, int **f, int n, int m, int i,
                                int j) {
  if (i < 1 || i > n) {
    return 0;
  }
  if (j < 0 || j > m) {
    return 0;
  }
  if (t->value[i] == 0) {
    return 0;
  }
  if (j == 1) {
    f[i][j] = t->value[i];
    return f[i][j];
  }
  if (f[i][j]) {
    return f[i][j];
  }

  for (int p = 0; p < j; p++) {
    int l = MaximumBinaryTreeRec(t, f, n, m, t->left[i], p);
    int r = MaximumBinaryTreeRec(t, f, n, m, t->right[i], j - p - 1);
    f[i][j] = std::max(l, r) + t->value[i];
  }
  return f[i][j];
}

int MaximumBinaryTree(MbTree *t, int n, int m) {
  int **f = Array2DNew(n + 1, m + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j] = 0;
    }
  }
  int result = MaximumBinaryTreeRec(t, f, n, m, 1, m);
  Array2DFree(f, n + 1);
  return result;
}

