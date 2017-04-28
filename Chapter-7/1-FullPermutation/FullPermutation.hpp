#ifndef FULL_PERMUTATION_HPP
#define FULL_PERMUTATION_HPP

// #include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

void FullPermutationImpl(vector<int> & A, int n, int prev, vector<vector<int>> & result)
{
    if (prev == 0) {
        result.push_back(A);
        return;
    }

    // 依次将A[prev]与它前面的prev-1个元素进行交换
    // i从prev开始 是为了产生一个初始化排列 该排列与A传入时完全一样
    for (int i = prev; i >= 0; i--) {
        swap(A[i], A[prev]);
        FullPermutationImpl(A, n, prev-1, result);
        swap(A[i], A[prev]);
    }
}

vector<vector<int>> FullPermutation(int s[MAX], int n)
{
    // 初始化 A=[s1, s2, s3, ..., sn]
    vector<int> A;
    for (int i = 0; i < n; i++)
        A.push_back(s[i]);

    vector<vector<int>> perm;

    FullPermutationImpl(A, n, n-1, perm);

    /*
    cout << endl;
    for (int i = 0; i < perm.size(); i++) {
        for (int j = 0; j < perm[i].size(); j++)
            cout << perm[i][j] << " ";
        cout << endl;
    }
    */

    return perm;
}


#endif
