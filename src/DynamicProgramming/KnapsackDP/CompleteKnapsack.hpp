#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
#include <vector>

int CompleteKnapsack(int *value, int *weight, int count, int tot_weight) {
    int f[MAX][MAX];

    // 初始化
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            f[i][j] = 0;
        }
    }

    for (int i = 1; i <= count; i++) {
        for (int j = 0; j <= tot_weight; j++) {
            // 珠宝 i 最多可以装 max_count 个
            int max_count = j / weight[i];
            for (int k = 0; k <= max_count; k++) {
                f[i][j] = std::max(f[i - 1][j],
                                   f[i - 1][j - k * weight[i]] + k * value[i]);
            }
        }
    }

    return f[count][tot_weight];
}
