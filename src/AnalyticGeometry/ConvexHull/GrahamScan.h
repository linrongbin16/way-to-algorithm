#pragma once
#include "../Polygon/Cross.h"
#include "../Util.h"
#include <stack>
#include <vector>
#ifndef INF
#define INF INT_MAX
#endif

void GrahamScan(std::vector<Node> s, std::stack<Node> &stk);

