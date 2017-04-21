#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


unordered_set<int> VectorToSet(int s[MAX], vector<int> & choose)
{
    unordered_set<int> r;
    for (int i = 0; i < choose.size(); i++)
        if (choose[i])
            r.insert(s[i]);
    return r;
}

vector<unordered_set<int>> Combination(int s[MAX], int n, int m)
{
    // 初始化 A=[1, 1, 1, 0, ..., 0]
    vector<int> choose;
    for (int i = 0; i < n; i++) {
        if (i < m)
            choose.push_back(1);
        else
            choose.push_back(0);
    }

    vector<unordered_set<int>> comb;

    if (n == m) {
        comb.push_back(VectorToSet(s, choose));
        return comb;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            std::swap(choose[j], choose[j+1]);
            // 过滤掉 A[j] == A[j+1] 的情况
            if (choose[j] != choose[j+1])
                comb.push_back(VectorToSet(s, choose));
        }
    }

    cout << endl;
    for (int i = 0; i < comb.size(); i++) {
        for (unordered_set<int>::iterator j = comb[i].begin(); j != comb[i].end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }

    return comb;
}


#endif
