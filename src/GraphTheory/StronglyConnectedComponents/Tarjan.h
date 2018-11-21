#pragma once
#include <climits>
#include <vector>
#ifndef MAX
#define MAX 64
#endif
#ifndef INF
#define INF INT_MAX
#endif

std::vector<std::vector<int>> Tarjan(int g[MAX][MAX], int n);

