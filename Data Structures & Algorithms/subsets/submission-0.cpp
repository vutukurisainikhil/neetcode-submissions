class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0, {}, nums, res);
        return res;
    }

    void backtrack(int idx, vector<int> curr, vector<int> nums, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = idx; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums, res);
            curr.pop_back();
        }
    }
};
