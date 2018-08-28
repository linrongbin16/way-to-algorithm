#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
#include <vector>

// 前i个物品重量不超过j的最大价值
int ZeroOneBag(int *value, int *weight, int count, int tot_weight);
