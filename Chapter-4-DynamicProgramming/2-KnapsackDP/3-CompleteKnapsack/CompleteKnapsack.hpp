#ifndef COMPLETE_KNAPSACK
#define COMPLETE_KNAPSACK

#ifndef MAX
#define MAX 1024
#endif
#include <vector>
#include <algorithm>
using namespace std;


int f[MAX][MAX];

int CompleteKnapsack(const int value[MAX], const int weight[MAX], int count, int total_weight)
{
    // 初始化
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            f[i][j] = 0;
        }
    }

    for (int i = 1; i <= count; i++) {
        for (int j = 0; j <= total_weight; j++) {
            // 珠宝i最多可以装max_count个
            int max_count = j / weight[i];
            for (int k = 0; k <= max_count; k++) {
                f[i][j] = max(f[i-1][j], f[i-1][ j - k*weight[i] ] + k*value[i]);
            }
        }
    }

    return f[count][total_weight];
}


#endif
