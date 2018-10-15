#include "MaxBinaryTreeRadiusSum.h"
#include "../Util.h"
#include <algorithm>
#include <cassert>
#include <cstring>

BrsNode *MaxBinaryTreeRadiusSumNew(int *value, int *left, int *right, int n) {
  BrsNode *t = new BrsNode[n + 1];
  std::memset(t, 0, sizeof(BrsNode) * (n + 1));
  for (int i = 1; i <= n; i++) {
    t[i].index = i;
    t[i].value = value[i];
    t[i].left = &t[left[i]];
    t[i].right = &t[right[i]];
    t[left[i]].father = &t[i];
    t[right[i]].father = &t[i];
  }
}

void MaxBinaryTreeRadiusSumFree(BrsNode *t) {
  assert(t);
  BrsNode *tb = (BrsNode *)((char *)t - sizeof(BrsNode));
  delete[] tb;
}

static void UpForeach(BrsNode *e, int **f, int j, int n) {
  if (e == NULL)
    return;
}

static void Up(BrsNode *e, int **f, int j, int n) {
  assert(e);
  assert(f);

  // PreOrder
}

static void Down(BrsNode *e, int **g, int j, int n) {
  assert(g);
  if (e == NULL) {
    return;
  }
}

static void Sum(BrsNode *e, int **h, int j, int n) {
  assert(h);
  if (e == NULL) {
    return;
  }
}

int MaxBinaryTreeRadiusSum(BrsNode *t, int radius, int n) {
  int **f = Array2DNew(n + 1, MAX);
  int **g = Array2DNew(n + 1, MAX);
  int **h = Array2DNew(n + 1, MAX);

  // 初始化

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= radius; j++) {
      f[i][j] = 0;
      g[i][j] = 0;
      h[i][j] = 0;
    }
  }

  // 分别向上/向下/求和

  Up(t, f, radius, n);
  Down(t, h, radius, n);
  Sum(t, g, radius, n);

  int result = 0;
  for (int i = 1; i <= n; i++) {
    result = std::max(h[i][radius], result);
  }
  Array2DFree(f, n + 1);
  Array2DFree(g, n + 1);
  Array2DFree(h, n + 1);
  return result;
}

#pragma once
void traverse_down(tree_node *r, int **fdown, int level);
void traverse_up(tree_node *r, int **fdown, int **fup, int level);
void get_father(tree_node *r, tree_node *p, int **fdown, int **fup, int level,
                int prev);
int traverse_max(tree_node *r, int **fdown, int **fup, int level);

int traverse_tree(
    tree_node *r, int **fdown, int **fup,
    int level) { // fdown[i][j]指代从第1层到第j层的向下权值之和
                 // fup[i][j]指代节点i向上第j层的最大权值 与fdown的意义是不同的
                 // fup[i][j]只指代第j层的权值之和
                 // fdown和fup初始化均为0
  traverse_down(r, fdown, level);
  traverse_up(r, fdown, fup, level);
  return (traverse_max(r, fdown, fup, level));
}
void traverse_down(tree_node *r, int **fdown,
                   int level) { //从底向上递归的寻找树中每个节点的向下最大权值
                                //这个递归是向下level层的递归
  //递归终止条件
  //若当前节点r是叶子节点
  if (r->t_cnt == 0) {
    //如果r节点的孩子节点数量t_cnt为0 它是叶子节点
    for (int i = 1; i <= level; ++i)
      //它的向下从第1层到第level层的最大权值都是0
      fdown[r->t_idx][i] = 0;
    return;
  }

  //如果r节点既不是叶子节点
  //它的孩子节点也没有得到各自的向下最大权值
  for (int i = 0; i < r->t_cnt; ++i)
    //继续遍历它的所有孩子节点i
    traverse_down(r->t_child[i], fdown, level);
  //遍历之后得到r的所有孩子节点的向下权值 再计算r的向下权值
  for (int i = 1; i <= level; ++i) {
    fdown[r->t_idx][i] = 0;
    for (int j = 0; j < r->t_cnt; ++j)
      fdown[r->t_idx][i] +=
          fdown[r->t_child[j]->t_idx][i - 1] + r->t_child[j]->t_value;
  }
}
void traverse_up(
    tree_node *r, int **fdown, int **fup,
    int level) { //用先序遍历树的方法遍历每个节点找出其向上的最大权值
                 //实际竞赛题目中 使用最简单的数组与下标来构建树 则也可以使用bfs
  if (r != NULL) {
    get_father(r, r, fdown, fup, level, 1);
    for (int i = 0; i < r->t_cnt; ++i)
      traverse_up(r->t_child[i], fdown, fup, level);
  }
}
void get_father(tree_node *r, tree_node *p, int **fdown, int **fup, int level,
                int prev = 1) { //递归的向上求出r到达 p 祖父节点那一层的最大权值
                                // p指代r向上第 prev-1 层的祖父节点
                                // prev == 1时 p即为r自己 p->t_fa为r的父节点
                                // prev > level时 已经超越了向上的最大层数level
  //递归终止条件
  //若p的父节点为空指针 即p已经为根节点
  if (p->t_fa == NULL)
    return;
  // prev > level是递归结束条件
  if (prev > level)
    return;

  if (prev == level) {
    //到达最高的祖父节点时 不访问孩子子树
    fup[r->t_idx][prev] = p->t_fa->t_value;
  } else {
    //其他祖父节点可以到达其孩子子树
    for (int i = 0; i < p->t_fa->t_cnt; ++i)
      //遍历p点的父节点的所有孩子节点 除过自己
      //即遍历p点的所有兄弟节点
      if (p->t_fa->t_child[i] != p) {
        //累加父节点的向下权值时要除去p自己这一子树的分支
        // r节点向上prev层的最大权值等于
        //上面prev层的祖父节点的所有孩子节点的向下 level-prev-1 层的最大权值
        //再加上孩子节点自己的权值
        fup[r->t_idx][prev] +=
            fdown[p->t_fa->t_child[i]->t_idx][level - prev - 1];
        fup[r->t_idx][prev] += p->t_fa->t_child[i]->t_value;
      }
    //还要加上p的父节点的权值
    fup[r->t_idx][prev] += p->t_fa->t_value;
  }
  //递归上一层父节点
  get_father(r, p->t_fa, fdown, fup, level, prev + 1);
}
int traverse_max(tree_node *r, int **fdown, int **fup,
                 int level) { //第三次遍历寻找多叉树中最大权值的点 返回该点权值
  //递归终止条件 空节点的权值为0
  if (r == NULL)
    return (0);

  int fmax(0);
  // fup[i][j]指代节点i向上第j层的那个祖父节点的所有孩子节点(除过自己这一分支)
  //的向下 level-j-1 层的权值之和(所有孩子节点的权值之和)
  //与fdown的意义是不同的 fdown[i][j]指代从第1层到第j层的向下权值之和
  // r点的最大权值等于所有向下节点的权值之和
  fmax += fdown[r->t_idx][level];
  //再加所有向上节点的权值之和
  for (int i = 1; i <= level; ++i)
    fmax += fup[r->t_idx][i];
  //再加自己的权值
  fmax += r->t_value;

  //再和所有其他的节点进行比较 选出最大的返回
  for (int i = 0; i < r->t_cnt; ++i)
    fmax = max(fmax, traverse_max(r->t_child[i], fdown, fup, level));
  return (fmax);
}

