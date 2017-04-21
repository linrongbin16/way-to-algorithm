#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

set<int> VectorToSet(int s[MAX], vector<int> & index)
{
    set<int> r;
    for (int i = 0; i < index.size(); i++)
        r.insert(s[ index[i] ]);
    return r;
}

vector<set<int>> Combination(int s[MAX], int n, int m)
{
    // 初始化 A=[1, 1, 1, 0, ..., 0]
    vector<int> index;
    for (int i = 0; i < m; i++)
        index.push_back(1);

    vector<set<int>> perm;

    if (n == m) {
        perm.push_back(VectorToSet(s, index));
        return perm;
    }
    if (n == 1) {
        perm.push_back(VectorToSet(s, index));
        return perm;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n-1; j++) {
            std::swap(index[j], index[j+1]);
            // 过滤掉 A[j] == A[j+1] 的情况
            if (index[j] != index[j+1])
                perm.push_back(VectorToSet(s, index));
        }
    }

    assert(perm.size() == n * (n-1));
    return perm;
}


#endif
