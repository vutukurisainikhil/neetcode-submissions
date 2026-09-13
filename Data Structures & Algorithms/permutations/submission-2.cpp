class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, nums, 0, res);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& curr, int index, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(curr);
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            dfs(nums, curr, index + 1, res);
            swap(nums[i], nums[index]);
        }
    }
};
