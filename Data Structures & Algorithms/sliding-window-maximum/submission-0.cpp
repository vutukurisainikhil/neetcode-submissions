class Solution {
public:
    // Time: O(n) — each index is pushed and popped at most once across the whole loop.
    // Space: O(k) — deque holds at most k indices.
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Deque stores INDICES (not values) of "still-relevant" candidates for the max.
        // Invariant: values at these indices are monotonically DECREASING from front to back.
        // So the front is always the max of the current window.
        deque<int> q;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            
            // Step 1: Remove indices that have slid OUT of the window.
            // Window of size k ending at i covers indices [i-k+1, i].
            // Anything older than that is no longer eligible.
            while (q.size() > 0 && q.front() < i - k + 1) {
                q.pop_front();
            }
            
            // Step 2: Kill weaker candidates from the BACK of the deque.
            // If a previous candidate is <= nums[i], it can never beat nums[i]
            // in any window that contains nums[i] — AND it'll leave the window
            // first (it's older). So it's permanently useless. Drop it.
            // This is what keeps the deque monotonically decreasing.
            while (q.size() > 0 && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            
            // Step 3: Add the current index as a new candidate.
            // It might be the max of the current window, or some future one.
            q.push_back(i);

            // Step 4: Once we've seen at least k elements, record the window's max.
            // The front of the deque is guaranteed to be the max because:
            //   (a) out-of-window indices are removed (Step 1)
            //   (b) the deque is monotonically decreasing (Step 2)
            if (i + 1 >= k) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};