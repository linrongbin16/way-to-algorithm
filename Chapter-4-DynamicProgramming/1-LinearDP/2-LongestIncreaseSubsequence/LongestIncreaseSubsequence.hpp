#ifndef LONGEST_INCREASE_SUBSEQUENCE
#define LONGEST_INCREASE_SUBSEQUENCE

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;


// 序列a和b的范围是[1,n]
int f[MAX];

int LongestIncreaseSubsequence(const int s[MAX], int n)
{
    // 初始化
    f[0] = 0;

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        int max_length = 0;
        for (int k = 1; k < i; k++) {
            if (s[i] >= s[k])
                max_length = max(max_length, f[k]);
        }
        f[i] = max_length+1;
    }

    int lis = 1;
    for (int i = 1; i <= n; i++) {
        lis = max(lis, f[i]);
    }

    return lis;
}


#endif
