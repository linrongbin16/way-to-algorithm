#pragma once
#include "../Polygon/Cross.h"
#include "../Util.h"
#include <stack>
#include <vector>

void GrahamScan(std::vector<Node> s, std::stack<Node> &stk);

