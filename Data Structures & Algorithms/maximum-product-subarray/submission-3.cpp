class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        // Track max and min: a negative number can turn the min into the new max.
        int currentMax = nums[0], currentMin = nums[0], best = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            // Candidates: start fresh at n, or extend previous max/min.
            int tempMax = max({n, currentMax * n, currentMin * n});
            int tempMin = min({n, currentMax * n, currentMin * n});
            // Use temps so currentMax isn't overwritten before currentMin is computed.
            currentMax = tempMax;
            currentMin = tempMin;
            best = max(best, currentMax);
        }
        return best;
    }
};