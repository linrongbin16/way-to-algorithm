#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
#include <vector>

// TODO bug need fix

int ZeroOneBagExtension(int *value, int *weight, int count, int tot_weight,
                        bool *choose);
