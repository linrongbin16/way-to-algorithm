#ifndef COMBINATORIAL_MATHEMATICS_DUPLICABLE_COMBINATION_HPP
#define COMBINATORIAL_MATHEMATICS_DUPLICABLE_COMBINATION_HPP

#include <algorithm>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

void backtrack(vector<vector<int>> &comb, vector<int> &tmp, int nums[MAX], int remain, int start) {
    if (remain < 0)
        return;
    if (remain == 0) {
        comb.push_back(tmp);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        tmp.push_back(nums[i]);
        backtrack(comb, tmp, nums, remain - nums[i], i);
        tmp.erase(tmp.end()-1);
    }
}

vector<vector<int>> DuplicableCombination(int candidates[MAX], int target) {
    vector<vector<int>> comb;
    std::sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    backtrack(comb, tmp, candidates, target, 0);
    return comb;
}


#endif
