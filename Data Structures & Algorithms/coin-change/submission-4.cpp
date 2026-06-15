class Solution {
   public:
    // Time complexity: O(n∗t)
    // DP classical knapsnack

    /*
    1D knapsack direction:
    - Unbounded (item reusable): inner loop ascending j = item to target.
    - 0/1 (item used once): inner loop descending j = target to item.
    */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  // sentinel = amount + 1
        dp[0] = 0;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        // check amount, as we initialize with amount+1 as sentinel.
        return dp[amount] > amount ? -1 : dp[amount];
    }
};