class Solution {
   public:
    /*
    1D knapsack direction:
    - Unbounded (item reusable): inner loop ascending j = item to target.
    - 0/1 (item used once): inner loop descending j = target to item.
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Impossible cases.
        if (abs(target) > totalSum) return 0;
        if ((target + totalSum) % 2 != 0) return 0;
        // Target Sum: partition into P (positive group) and N (negative
        // group). Then sum(P) = (target + totalSum) / 2
        int subsetSum = (target + totalSum) / 2;

        // 0/1 knapsack: count number of subsets summing to subsetSum.
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;  // one way to make 0 (empty subset)

        for (int num : nums) {
            // Descending → 0/1 knapsack (each num used at most once).
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};