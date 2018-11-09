#include "MaximumMultipleTree.h"
#include "../Util.h"
#include <cassert>
#include <cstring>

MtNode *MaximumMultipleTreeNew(int *value, int *father, int n) {
  MtNode *t = new MtNode[n + 1];
  std::memset(t, 0, sizeof(MtNode) * (n + 1));
  for (int i = 1; i <= n; i++) {
    t[i].index = i;
    t[i].value = value[i];
    if (father[i]) {
      t[father[i]].child_cnt++;
      t[father[i]].child[t[father[i]].child_cnt] = &t[i];
    }
  }
  return &t[1];
}

void MaximumMultipleTreeFree(MtNode *t) {
  assert(t);
  MtNode *tb = (MtNode *)((char *)t - sizeof(MtNode));
  delete[] tb;
}

static int MaximumMultipleTreeRec(MtNode *t, int **f, int n, int m, int j);
static void Recursion(MtNode *t, int **f, int n, int m, int j, int p,
                      int *assign_cnt);

static void Recursion(MtNode *t, int **f, int n, int m, int j, int p,
                      int *assign_cnt) {
  assert(t);
  assert(f);

  if (p == t->child_cnt + 1) {
    int sum_f = 0;
    for (int k = 1; k <= t->child_cnt; k++) {
      sum_f += MaximumMultipleTreeRec(t->child[k], f, n, m, assign_cnt[k]);
    }
    f[t->index][j] = sum_f;
    return;
  }

  // 最后一个孩子节点

  if (p == t->child_cnt) {
    assign_cnt[p] = j;
    Recursion(t, f, n, m, 0, p + 1, assign_cnt);
  } else {
    for (int k = 0; k <= j; k++) {
      assign_cnt[p] = k;
      Recursion(t, f, n, m, j, p + 1, assign_cnt);
    }
  }
}

static int MaximumMultipleTreeRec(MtNode *t, int **f, int n, int m, int j) {
  assert(t);
  assert(f);
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

  // 孩子节点p的子树上保留节点数量为assign_cnt[p]
  // 1 <= p <= t->child_cnt

  int assign_cnt[MAX];
  std::memset(assign_cnt, 0, sizeof(int) * MAX);
  Recursion(t, f, n, m, j, 1, assign_cnt);
  return f[t->index][j];
}

int MaximumMultipleTree(MtNode *t, int n, int m) {
  int **f = Array2DNew(n + 1, m + 1);
  int result = MaximumMultipleTreeRec(t, f, n, m, 1);
  Array2DFree(f, n + 1);
  return result;
}

