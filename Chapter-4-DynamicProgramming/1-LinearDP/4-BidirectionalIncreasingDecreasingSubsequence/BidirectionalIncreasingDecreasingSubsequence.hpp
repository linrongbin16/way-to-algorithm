#ifndef LONGEST_INCREASING_SUBSEQUENCE_EXTENSION
#define LONGEST_INCREASING_SUBSEQUENCE_EXTENSION

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;


int f[MAX], g[MAX];

void LongestIncreasingSubsequence(const int s[MAX], int n)
{
    // 初始化
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        f[i] = 1;

    for (int i = 1; i <= n; i++) {
        int max_length = 0;
        for (int k = 1; k < i; k++) {
            if (s[i] > s[k])
                max_length = max(max_length, f[k]);
        }
        f[i] = max_length+1;
    }
}

void LongestDecreasingSubsequence(const int s[MAX], int n)
{
    // 初始化
    g[0] = 0;
    for (int i = n; i >= 1; i--)
        g[i] = 1;

    for (int i = n; i >= 1; i--) {
        int max_length = 0;
        for (int k = n; k > i; k--) {
            if (s[i] > s[k])
                max_length = max(max_length, g[k]);
        }
        g[i] = max_length+1;
    }
}

int BidirectionalIncreasingDecreasingSubsequence(const int s[MAX], int n)
{
    LongestIncreasingSubsequence(s, n);
    LongestDecreasingSubsequence(s, n);

    int bimax = 0;

    for (int i = 1; i <= n; i++) {
        bimax = max(f[i]+g[i]-1, bimax);
    }

    return bimax;
}


#endif
