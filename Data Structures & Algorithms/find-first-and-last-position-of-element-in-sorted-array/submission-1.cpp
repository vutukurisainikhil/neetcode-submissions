class Solution {
public:
    // single style of binary search that finds the insertion point for a value
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int start = binarySearch(nums, target, n);
        if (start == n || nums[start] != target) {
            return {-1, -1};
        }

        return {start, binarySearch(nums, target + 1, n) - 1};
    }

private:
    int binarySearch(vector<int>& nums, int target, int n) {
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};