#ifndef FULL_PERMUTATION_HPP
#define FULL_PERMUTATION_HPP

#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

vector<vector<int>> FullPermutation(int s[MAX], int n)
{
    // 初始化 A=[s-1, s-2, s-3, ..., s-n]
    vector<int> A;
    for (int i = 0; i < n; i++)
        A.push_back(s[i]);

    vector<vector<int>> perm;

    if (n == 1) {
        perm.push_back(A);
        return perm;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n-1; j++) {
            std::swap(A[j], A[j+1]);
            perm.push_back(A);
        }
    }

    assert(perm.size() == n * (n-1));
    return perm;
}


#endif
