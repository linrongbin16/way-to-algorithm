#include "MaximumBinaryTree.h"
#include "../Util.h"
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstring>

BiNode *MaximumBinaryTreeNew(int *value, int *left, int *right, int n) {
  BiNode *t = new BiNode[n + 1];
  std::memset(t, 0, sizeof(BiNode) * (n + 1));
  for (int i = 1; i <= n; i++) {
    t[i].index = i;
    t[i].value = value[i];
    t[i].left = &t[left[i]];
    t[i].right = &t[right[i]];
  }
  return &t[1];
}

void MaximumBinaryTreeFree(BiNode *t) {
  assert(t);
  // 找到实际的数组指针
  BiNode *node_tb = (BiNode *)((char *)t - sizeof(BiNode));
  delete[] node_tb;
}

static int MaximumBinaryTreeRec(BiNode *t, int **f, int n, int m, int j) {
  if (t == NULL) {
    return 0;
  }
  if (t->index < 1 || t->index > n) {
    return 0;
  }
  if (t->value == 0) {
    return 0;
  }
  if (j < 0 || j > m) {
    return 0;
  }
  if (j == 1) {
    f[t->index][j] = t->value;
    return f[t->index][j];
  }
  if (f[t->index][j]) {
    return f[t->index][j];
  }

  for (int p = 0; p < j; p++) {
    int l = MaximumBinaryTreeRec(t->left, f, n, m, p);
    int r = MaximumBinaryTreeRec(t->right, f, n, m, j - p - 1);
    f[t->index][j] = std::max(l, r) + t->value;
  }
  return f[t->index][j];
}

int MaximumBinaryTree(BiNode *t, int n, int m) {
  int **f = Array2DNew(n + 1, m + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j] = 0;
    }
  }
  int result = MaximumBinaryTreeRec(t, f, n, m, m);
  Array2DFree(f, n + 1);
  return result;
}

