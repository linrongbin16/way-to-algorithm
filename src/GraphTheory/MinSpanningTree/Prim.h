#pragma once
#include "../Util.h"
#include <limits>
#include <vector>
#ifndef MAX
#define MAX 64
#endif
#ifndef INF
#define INF INT_MAX
#endif

std::vector<Edge> Prim(int g[MAX][MAX], int n);

