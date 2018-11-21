#pragma once
#include <utility>
#include <vector>
#ifndef MAX
#define MAX 64
#endif

std::pair<bool, std::vector<int>> DifferenceConstraints(int a[MAX][MAX], int n,
                                                        int m, int *b);

