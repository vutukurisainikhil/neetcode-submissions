class Solution {
   public:
       /*
    1D knapsack direction:
    - Unbounded (item reusable): inner loop ascending j = item to target.
    - 0/1 (item used once): inner loop descending j = target to item.
    */
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        // for combinations of coins, outer-loop is coins.
        // for each coin, can we gwt to target ?.
        for (auto c : coins) {
            for (int j = c; j <= amount; j++) {
                dp[j] += dp[j - c];
            }
        }
        return dp[amount];
    }
};
