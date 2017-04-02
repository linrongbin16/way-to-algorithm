#ifndef TWO_DIMENSION_KNAPSACK
#define TWO_DIMENSION_KNAPSACK

#ifndef MAX
#define MAX 128
#endif
#include <vector>
#include <algorithm>
using namespace std;

// TODO: fix bug

int f[MAX][MAX][MAX];

int TwoDimensionKnapsack(const int value[MAX], const int weight1[MAX], const int weight2[MAX], int count, int w1, int w2)
{
    // ≥ı ºªØ
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                f[i][j][k] = 0;

    for (int i = 1; i <= count; i++) {
        for (int j = 0; j <= w1; j++) {
            for (int k = 0; k <= w2; k++) {
                if (j >= weight1[i] && k >= weight2[i]) {
                    f[i][j][k] = max( f[i-1][j][k], f[i-1][ j - weight1[i] ][ k - weight2[i] ] + value[i] );
                } else {
                    f[i][j][k] = f[i-1][j][k];
                }
            }
        }
    }

    return f[count][w1][w2];
}


#endif
