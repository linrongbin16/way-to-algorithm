#pragma once
#ifndef MAX
#define MAX 64
#endif
#include <vector>

/**
 * @brief 拓扑排序
 * @param G   有向图
 * @param n   图中节点数量 下标为[0, n-1]
 * @return    拓扑排序结果
 */
std::vector<int> TopologicalSort(int G[MAX][MAX], int n);

