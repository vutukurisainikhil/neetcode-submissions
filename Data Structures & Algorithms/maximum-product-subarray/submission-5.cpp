class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        // Track max and min: a negative number can turn the min into the new max.
        int currentMax = nums[0], currentMin = nums[0], best = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // Candidates: start fresh at nums[i], or extend previous max/min.
            int tempMax = max({nums[i], currentMax * nums[i], currentMin * nums[i]});
            int tempMin = min({nums[i], currentMax * nums[i], currentMin * nums[i]});
            // Use temps - so currentMax isn't overwritten before currentMin is computed.
            currentMax = tempMax;
            currentMin = tempMin;
            best = max(best, currentMax);
        }
        return best;
    }
};