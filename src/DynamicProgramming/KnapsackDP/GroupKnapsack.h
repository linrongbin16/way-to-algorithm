#pragma once
#ifndef MAX
#define MAX 1024
#endif

/**
 * 物品分为 n 组
 * 第 i 组中有 group_n[i] 个物品 范围为 [ 1, group_n[i] ]
 * group[i][j] 为第 i 组中的第 j 个物品
 * 该物品 item 的价值为 item.value 重量为 item.weight
 * 背包能装载的最大重量为 tot_weight
 */
struct Item {
    int value;
    int weight;
};

int GroupKnapsack(Item group[MAX][MAX], int *group_n, int n, int tot_weight);
