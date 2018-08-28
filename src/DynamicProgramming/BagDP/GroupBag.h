#pragma once
#ifndef MAX
#define MAX 1024
#endif

/**
 * 物品分为n组
 * 第i组中有group_n[i]个物品 范围为[1, group_n[i]]
 * group[i][j]为第i组中的第j个物品
 * 该物品item的价值为item.value重量为item.weight
 * 背包能装载的最大重量为tot_weight
 */
struct Item {
  int value;
  int weight;
};

int GroupBag(Item group[MAX][MAX], int *group_n, int n, int tot_weight);

