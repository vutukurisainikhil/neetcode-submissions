class Solution {
public:
    // concept: Dp Subset Sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        int subsetSum = sum / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // reaching 0, then solution is possible
        for (auto x: nums) {
            for (int j = subsetSum; j >= x; j--) {
                // Include or Exclude the nums[i].
                dp[j] = dp[j] | dp[j - x];
            }
        }
        return dp[subsetSum];
    }
};