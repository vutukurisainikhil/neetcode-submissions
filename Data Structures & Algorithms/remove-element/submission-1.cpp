class Solution {
public:
    // TimeComplexity:O(n)
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                // reordering the nums
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};