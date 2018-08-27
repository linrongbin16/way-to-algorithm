#pragma once
#include <stack>
#include <vector>
#include "../Polygon/Cross.h"
#include "../Util.h"

void GrahamScan(std::vector<Node> s, std::stack<Node>& stk);
