#pragma once
#ifndef MAX
#define MAX 128
#endif

struct Item {
  int v;
  int w;
};

/**
 * @param   group[i][j]表示第i组第j个物品的价值v和重量w
 * @param   m表示组的数量 group[i][j]满足1<=i<=m
 * @param   n[i]表示第i组的物品数量
 * @param   weight为背包最大重量
 * @return  返回背包能够装载的最大价值
 */
int GroupBag(Item group[MAX][MAX], int m, int n[MAX], int weight);

