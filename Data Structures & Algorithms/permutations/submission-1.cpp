class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        combinations(nums, 0, nums.size() - 1);
        return res;
    }
    void combinations(vector<int>& nums, int index, int end) {
        if (index == end) {
            res.push_back(nums);
        }
        for (int i = index; i <= end; i++) {
            swap(nums[index], nums[i]);
            combinations(nums, index + 1, end);  // index+1
            swap(nums[index], nums[i]);
        }
    }
};