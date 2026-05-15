class Solution {
public:
    // Timecomplexity: 0(n), as unordered_set - insert,find is O(1)
    bool hasDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};