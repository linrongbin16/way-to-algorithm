#ifndef COMBINATORIAL_MATHEMATICS_DUPLICABLE_COMBINATION_HPP
#define COMBINATORIAL_MATHEMATICS_DUPLICABLE_COMBINATION_HPP

#include <algorithm>
#include <vector>
using namespace std;

auto Recursion(vector<int> &tmp, const vector<int> &candidates, int prev, vector<vector<int>> &comb) -> void
{
    /* 递归终止条件 */
    if (prev == tmp.size()) {
        comb.push_back(tmp);
        return;
    }

    /* 遍历当前成员s[prev] 并递归进入下一个成员 */
    for (int i = 0; i < candidates.size(); i++) {
        tmp[prev] = candidates[i];
        Recursion(tmp, candidates, prev + 1, comb);
    }
}

auto DuplicableCombination(vector<int> &candidates, int n) -> vector<vector<int>> {
    vector<vector<int>> comb;
    vector<int> tmp(n, 0);
    Recursion(tmp, candidates, 0, comb);
    return comb;
}


#endif
