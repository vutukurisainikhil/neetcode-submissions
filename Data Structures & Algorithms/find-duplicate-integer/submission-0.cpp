class Solution {
   public:
    // Time Complexity: O(n);
    // Space Complexity: O(1)

    /*Logic : When we see a number, we go to its corresponding index and flip the sign of the value
    there. If we ever visit an index that is already negative, it means we've visited this number
    before → it's the duplicate. */

    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};