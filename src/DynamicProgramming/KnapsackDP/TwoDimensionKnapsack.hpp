#pragma once

#ifndef MAX
#define MAX 128
#endif
#include <algorithm>
#include <iostream>

int TwoDimensionKnapsack(int *value, int *weight1, int *weight2, int n, int w1,
                         int w2)
{
    int f[MAX][MAX][MAX];

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++) f[i][j][k] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w1; j++) {
            for (int k = 0; k <= w2; k++) {
                if (j >= weight1[i] && k >= weight2[i]) {
                    f[i][j][k] = std::max(
                        f[i - 1][j][k],
                        f[i - 1][j - weight1[i]][k - weight2[i]] + value[i]);
                }
                else {
                    f[i][j][k] = f[i - 1][j][k];
                }
            }
        }
    }

    return f[n][w1][w2];
}
