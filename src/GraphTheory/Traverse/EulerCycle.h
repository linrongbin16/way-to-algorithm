#pragma once
#include <vector>
#ifndef MAX
#define MAX 64
#endif

bool UndirectedGraphHasEulerCycle(int g[MAX][MAX], int n);

bool DirectedGraphHasEulerCycle(int g[MAX][MAX], int n);

std::vector<int> EulerCycle(int g[MAX][MAX], int n);

