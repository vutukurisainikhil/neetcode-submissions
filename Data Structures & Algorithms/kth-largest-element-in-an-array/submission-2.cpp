class Solution {
public:
    // TimeComplexity: O(n+m)
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        
        for (int num: nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }
        // finding frquency of each element.
        vector<int> count(maxValue - minValue + 1);
        for (int num: nums) {
            count[num - minValue]++;
        }
        // find k largest element.
        int remain = k;
        for (int num = count.size() - 1; num >= 0; num--) {
            remain -= count[num];
            if (remain <= 0) {
                return num + minValue;
            }
        }
        
        return -1;
    }
};