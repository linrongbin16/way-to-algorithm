#include "MaximumMultipleTree.h"
#include "../Util.h"
#include <cassert>
#include <cstring>

MtNode *MaximumMultipleTreeNew(int *value, int *father, int n) {
  MtNode *t = new MtNode[MAX];
  std::memset(t, 0, sizeof(MtNode) * MAX);
  for (int i = 1; i <= n; i++) {
    t[i].index = i;
    t[i].value = value[i];
    if (father[i]) {
      t[father[i]].child[t[father[i]].child_cnt++] = &t[i];
    }
  }
  return &t[1];
}

void MaximumMultipleTreeFree(MtNode *t) {
  assert(t);
  MtNode *tb = (MtNode *)((char *)t - sizeof(MtNode));
  delete[] tb;
}

static void Dfs(MtNode *t, int **f) {
  assert(t);
  assert(f);
}

static int MaximumMultipleTreeRec(MtNode *t, int **f, int n, int m, int j) {
  assert(t);
  assert(f);
  return 0;
}

int MaximumMultipleTree(MtNode *t, int n, int m) {
  int **f = Array2DNew(n + 1, m + 1);
  int result = MaximumMultipleTreeRec(t, f, n, m, 1);
  Array2DFree(f, n + 1);
  return result;
}

#pragma once

#ifndef MAX
#define MAX 60
#endif
#include <algorithm>
using namespace std;

struct multiple_tree_node {
  int m_index;
  int m_value;
  int m_count;
  multiple_tree_node *m_child[MAX];
};

int multiple_tree(multiple_tree_node *r, int f[MAX][MAX], int resv);

void depth_search(multiple_tree_node *r, int f[MAX][MAX], int next_resv[MAX],
                  int resv, int left_resv, int prev) {
  //处理对当前r的所有孩子节点的分配工作
  //给节点r分配的剩余节点为resv个
  //给r的所有孩子节点分配的节点存储在next_resv数组中
  //将r的孩子树们分配的所有情况中的最大权值挑选出来赋给f[r->m_index][resv]
  //只处理当前r节点 不会处理到下一层的节点
  //递归结束条件 深度搜索出一种组合后进行计算
  if (prev == r->m_count) {
    //更新r树的最大权值
    int sumf = 0;
    //下一层子树的最大权值又交给另一个递归去做
    for (int i = 0; i < r->m_count; ++i)
      sumf += multiple_tree(r->m_child[i], f, next_resv[i]);
    f[r->m_index][resv] = max(f[r->m_index][resv], sumf);
    return;
  }

  //对r的一个指定孩子prev
  if (prev == r->m_count - 1) {
    //如果prev是孩子节点中的最后一个 它直接分配到剩余的所有节点
    next_resv[prev] = left_resv;
    depth_search(r, f, next_resv, resv, 0, prev + 1);
  } else {
    //对于当前孩子prev 它可以分配的节点数从 0 到 left_resv
    for (int i = 0; i <= left_resv; ++i) {
      //当前孩子分配 i 个节点
      next_resv[prev] = i;
      //下一个孩子 prev+1 只能分配 left_resv-i 个节点
      depth_search(r, f, next_resv, resv, left_resv - i, prev + 1);
    }
  }
}

int multiple_tree(multiple_tree_node *r, int f[MAX][MAX], int resv) {
  //二叉树根节点为r 初始时f为0 保留resv个节点 返回最大权值
  if (r == NULL)
    return 0;
  if (resv == 0)
    return 0;
  //如果已经算出节点r上保留resv个节点所具有的最大权值f[r][resv]
  //则直接返回该值
  if (f[r->m_index][resv])
    return f[r->m_index][resv];

  // next_resv中存储着r的孩子们分配节点的数量
  int next_resv[MAX];
  for (int i = 0; i < r->m_count; ++i)
    next_resv[i] = 0;
  //要对当前节点r的所有孩子分配剩余的resv-1个节点(根节点自己占据1个)
  //用深度搜索找出所有可能 并将最大的权值赋给f[r->m_index][resv]
  depth_search(r, f, next_resv, resv, resv - 1, 0);
  f[r->m_index][resv] += r->m_value;
  return f[r->m_index][resv];
}

