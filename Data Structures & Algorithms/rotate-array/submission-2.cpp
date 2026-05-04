class Solution {
public:
    /* Time Complexity: 0(logn), SpaceComplexity: O(1)
Logic is very simple, without extra space we can do this by
        1. reverse whole array, from start to end.
        2. Now reverse array from start to k index.
        3. reverse the remianing array from k to n index.
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums, 0, n - 1);// reverse whole array
        reverse(nums, 0, k - 1);// reverse from start to k index
        reverse(nums, k, n - 1);// reverse the remianing array from k to n index
    }

private:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};