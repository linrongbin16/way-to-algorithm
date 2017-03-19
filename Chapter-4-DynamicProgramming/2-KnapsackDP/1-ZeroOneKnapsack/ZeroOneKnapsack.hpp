#ifndef ZERO_ONE_KNAPSACK
#define ZERO_ONE_KNAPSACK

#ifndef MAX
#define MAX 1024
#endif
#include <vector>
#include <algorithm>
using namespace std;


int f[MAX][MAX];

int ZeroOneKnapsack(const int value[MAX], const int weight[MAX], int count, int total_weight)
{
    // ≥ı ºªØ
    for (int i = 0; i < MAX; i++) {
        f[0][i] = 0;
        f[i][0] = 0;
    }

    for (int i = 1; i <= count; i++) {
        for (int j = 0; j <= total_weight; j++) {
            if (j >= weight[i])
                f[i][j] = max( f[i-1][j], f[i-1][j-weight[i]] + value[i]);
            else
                f[i][j] = f[i-1][j];
        }
    }

    return f[count][total_weight];
}


#endif
