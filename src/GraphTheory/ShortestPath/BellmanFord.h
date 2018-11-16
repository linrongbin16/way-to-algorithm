#pragma once
#include <climits>
#include <utility>
#include <vector>
#ifndef MAX
#define MAX 64
#endif
#ifndef INF
#define INF INT_MAX
#endif

std::tuple<bool, std::vector<int>, std::vector<int>>
BellmanFord(int g[MAX][MAX], int n, int beg);

