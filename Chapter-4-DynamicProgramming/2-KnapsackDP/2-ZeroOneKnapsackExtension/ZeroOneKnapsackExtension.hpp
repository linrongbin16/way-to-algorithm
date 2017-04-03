#ifndef ZERO_ONE_KNAPSACK
#define ZERO_ONE_KNAPSACK

#ifndef MAX
#define MAX 1024
#endif
#include <vector>
#include <algorithm>
using namespace std;

// TODO: 该算法有bug


int f[MAX][MAX];
bool g[MAX][MAX][MAX];

int ZeroOneKnapsackExtension(int value[MAX], int weight[MAX], int count, int total_weight, bool choose[MAX])
{
    // 初始化
    for (int i = 0; i < MAX; i++) {
        f[0][i] = 0;
        f[i][0] = 0;
    }

    for (int i = 1; i <= count; i++) {
        for (int j = 0; j <= total_weight; j++) {
            int old_f = f[i-1][j];
            if (j >= weight[i]) {
                int new_f = f[i-1][j - weight[i]] + value[i];
                if (old_f > new_f) {
                    f[i][j] = old_f;
                    g[i][j][old_f] = false;
                } else {
                    f[i][j] = new_f;
                    g[i][j][old_f] = true;
                }
            }
            else {
                f[i][j] = old_f;
                g[i][j][old_f] = false;
            }
        }
    }

    for (int i = 0; i < MAX; i++)
        choose[i] = 0;
    for (int i = count, w = total_weight, v = f[count][total_weight]; i >= 1; i--) {
        if (g[i][w][v]) {
            choose[i] = true;
            w -= weight[i];
            v -= value[i];
        }
    }

    return f[count][total_weight];
}


#endif
