class Solution {
public:
    //  Time Complexity : O(N)
    // Two Pointers
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            // Lesser side moves first
            if (height[left] < height[right]) {
                // if height[left] > left_max then Update, else caluclate water.
                height[left] >= left_max ? (left_max = height[left])
                                         : ans += (left_max - height[left]);
                ++left; // increment
            } else {
                height[right] >= right_max ? (right_max = height[right])
                                           : ans += (right_max - height[right]);
                --right; //decrement
            }
        }
        return ans;
    }
};