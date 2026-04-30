class Solution {
public:
    // timecomplexity: O(n)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : num_set) {
            // if num-1 not found then check for consecutive elements in set for LCS.
            if (!num_set.count(num - 1)) {
                int currentStreak = 1;
                while (num_set.count(num + currentStreak)) {
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
