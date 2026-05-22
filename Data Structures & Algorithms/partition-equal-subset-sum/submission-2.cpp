class Solution {
public:
    // Partition Equal Subset Sum (LC 416).
    //
    // Reduce to subset-sum: "is there a subset of nums whose sum equals total/2?"
    // If yes, the rest sums to total/2 too — the partition works.
    //
    // 0/1 knapsack DP, space-optimized to 1D:
    //   dp[j] = "can we form sum j using some subset of nums seen so far?"
    //
    // CRITICAL: iterate j DESCENDING. Going ascending would let each number be
    // reused (unbounded knapsack), which is wrong here — each num can be used at
    // most once.
    //
    // Time: O(n * sum/2), Space: O(sum/2).

    /*
    1D knapsack direction:
    - Unbounded (item reusable): inner loop ascending j = item to target.
    - 0/1 (item used once): inner loop descending j = target to item.
    */
    bool canPartition(vector<int>& nums) {
        // Step 1: Compute total sum. Odd → no equal partition possible.
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        
        // dp[j] = true iff some subset of processed nums sums to j.
        // Base case: dp[0] = true (empty subset sums to 0).
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        // Step 2: For each num, update reachable sums.
        // Descending j ensures dp[j-x] still reflects "before this num" — preventing reuse.
        for (int x : nums) {
            for (int j = target; j >= x; j--) {
                // Either we don't use x (dp[j] unchanged) or we use x (dp[j-x] becomes reachable).
                dp[j] = dp[j] | dp[j - x];
            }
        }
        
        return dp[target];
    }
};