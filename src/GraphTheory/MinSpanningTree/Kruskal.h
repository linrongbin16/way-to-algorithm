#pragma once
#include "../Util.h"
#include <vector>
#ifndef MAX
#define MAX 64
#endif

std::vector<Edge> Kruskal(int g[MAX][MAX], int n);

