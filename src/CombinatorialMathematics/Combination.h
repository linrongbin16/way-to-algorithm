#pragma once
#include <unordered_set>
#include <vector>
#ifndef MAX
#define MAX 1024
#endif

std::vector<std::unordered_set<int>> Combination(int s[MAX], int n, int m);

