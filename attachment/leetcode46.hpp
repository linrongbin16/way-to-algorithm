class Solution {
    void FullPermutationImpl(vector<int> &nums, int prev, vector<vector<int>> & result)
    {
        if (prev == 0) {
            result.push_back(nums);
            return;
        }
        for (int i = prev; i >= 0; i--) {
            swap(nums[i], nums[prev]);
            FullPermutationImpl(nums, prev-1, result);
            swap(nums[i], nums[prev]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        FullPermutationImpl(nums, nums.size()-1, ret);
        return ret;
    }
};


