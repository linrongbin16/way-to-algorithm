#ifndef COMBINATORIAL_MATHEMATICS_DUPLICABLE_COMBINATION_HPP
#define COMBINATORIAL_MATHEMATICS_DUPLICABLE_COMBINATION_HPP

#include <algorithm>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

auto Backtrack(vector<vector<int>> &comb, vector<int> &tmp, const vector<int> &nums, int remain, int start) -> void {
    if (remain < 0)
        return;
    if (remain == 0) {
        comb.push_back(tmp);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        tmp.push_back(nums[i]);
        Backtrack(comb, tmp, nums, remain - nums[i], i);
        tmp.erase(tmp.end()-1);
    }
}

auto DuplicableCombination(vector<int> &candidates, int target) -> vector<vector<int>> {
    vector<vector<int>> comb;
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    Backtrack(comb, tmp, candidates, target, 0);
    return comb;
}


#endif
