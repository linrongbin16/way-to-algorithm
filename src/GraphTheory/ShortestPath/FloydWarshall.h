#pragma once
#include <algorithm>
#include <vector>
#ifndef MAX
#define MAX 64
#endif

std::vector<std::vector<int>> FloydWarshall(int g[MAX][MAX], int n);

