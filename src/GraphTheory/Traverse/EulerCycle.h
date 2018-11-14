#pragma once
#include <utility>
#include <vector>
#ifndef MAX
#define MAX 64
#endif

// 无向图
// bool表示该无向图是否存在欧拉回路
// vector<int>表示该无向图的欧拉回路的节点顺序
std::pair<bool, std::vector<int>> EulerCycle(int g[MAX][MAX], int n);

