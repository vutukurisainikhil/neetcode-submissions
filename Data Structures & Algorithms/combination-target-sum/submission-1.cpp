class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        dfs(0, nums, target, 0, curr);
        return res;   
    }

    void dfs(int index, vector<int>& nums, int target, int sum, vector<int>& curr){
        if(target == sum){
            res.push_back(curr);
            return;
        }

        for(int i=index ;i<nums.size();i++){
            if(sum+nums[i] > target){
                return;
            }
            curr.push_back(nums[i]);
            dfs(i, nums, target, sum + nums[i], curr);
            curr.pop_back();
        }

    }
};
