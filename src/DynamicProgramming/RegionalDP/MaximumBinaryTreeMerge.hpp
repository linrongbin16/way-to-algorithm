#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
#include <iostream>

int MaximumBinaryTreeMerge(int *s, int n)
{
    // f[i][j]表示节点[i,j]的树的最大合并价值
    int f[MAX][MAX];
    //序列s的数量为n 范围是[1,n] 返回最小合并代价
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) f[i][j] = 1;
    for (int i = 1; i <= n; i++) f[i][i] = 1 + s[i];

    // 按照[i,j]范围的节点数量len来遍历
    // 当len=1时 所有合并情况是[1,2] [2,3] [3,4] ...
    // 当len=2时 所有合并情况是[1,3] [2,4] [3,5] ...
    // 当len=3时 所有合并情况是[1,4] [2,5] [3,6] ...
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            for (int k = i; k <= i + len && k <= n; k++) {
                // k==i或k+1==i+len时 f[i][k-1]或f[k+1][i+len]的值是没有意义的
                // 但我们将这些无意义的值都初始化为1
                // 把它们看作空子树的合并价值即可
                f[i][i + len] = std::max(
                    f[i][i + len], f[i][k - 1] * f[k + 1][i + len] + s[k]);
            }
        }
    }

    return f[1][n];
}
