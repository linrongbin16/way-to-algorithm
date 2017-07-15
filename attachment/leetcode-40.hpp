class Solution {
public:
    void backtrack(vector<vector<int>> &list, vector<int> &tempList, const vector<int> &nums, int remain, int start) {
        if (remain < 0)
            return;
        if (remain == 0) {
            list.push_back(tempList);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            tempList.push_back(nums[i]);
            backtrack(list, tempList, nums, remain - nums[i], i);
            tempList.erase(tempList.end()-1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        std::sort(candidates.begin(), candidates.end());
        vector<int> tempList;
        backtrack(list, tempList, candidates, target, 0);
        return list;
    }
};
