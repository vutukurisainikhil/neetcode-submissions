class Solution {
   public:
    // TimeComplexity: O(N^3)
    // SpaceComeplexity: O(N^2)
    // Analysis: Classical DP  Matric Chain Multiplication Bottom-Up.
    int maxCoins(vector<int>& nums) {
        // nums: [3,1,5,8]
        // Push 1, at the start and end of the nums, so that all border cases are covered.
        nums.push_back(1);
        nums.insert(nums.begin(), 1);  // [1,3,1,5,8,1]
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        // find all the combinations and memorize it by dp.
        // combination from end -> (i,k,j).
        for (int i = nums.size() - 3; i >= 0; i--) {     // i moves right -> left
            for (int j = i + 2; j < nums.size(); j++) {  // j moves left -> right
                for (int k = i + 1; k < j; k++) {        // k moves left -> right
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }
        // This DP goes in zig zag way as, (i) moves from right->left.
        // so at end answer resides in dp[0][nums.size()-1].
        return dp[0][nums.size() - 1];
    }
};
