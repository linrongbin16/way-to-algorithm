#ifndef TWO_DIMENSION_KNAPSACK
#define TWO_DIMENSION_KNAPSACK

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;

// TODO: fix bug


int f[MAX][MAX];

/**
 * 物品分为 n 组
 * 第 i 组中有 group_n[i] 个物品 范围为 [ 1, group_n[i] ]
 * group[i][j] 为第 i 组中的第 j 个物品
 * 该物品 item 的价值为 item.value_ 重量为 item.weight_
 * 背包能装载的最大重量为 total_weight
*/

struct Item {
    int value_;
    int weight_;
};

bool ItemCompare(const Item & a, const Item & b)
{
    double rate_a = (double)a.value_ / (double)a.weight_;
    double rate_b = (double)b.value_ / (double)b.weight_;
    if (rate_a != rate_b)
        return rate_a > rate_b;
    else
        return a.weight_ < b.weight_;
}

int GroupKnapsack(Item group[MAX][MAX], int group_n[MAX], int n, int total_weight)
{
    // 初始化
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            f[i][j] = 0;

    // 对所有分组进行排序
    for (int i = 1; i < n; i++)
        sort( (Item*)group[i] + 1, (Item*)group[i] + 1 + group_n[i], ItemCompare );

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= group_n[k]; i++) {
            for (int j = 0; j <= total_weight; j++) {
                if (j >= group[k][i].weight_) {
                    f[k][j] = max( f[k-1][j], f[k-1][j - group[k][i].weight_ ] + group[k][i].value_ );
                } else {
                    f[k][j] = f[k-1][j];
                }
            }
        }
    }

    return f[n][total_weight];
}


#endif
