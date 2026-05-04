class Solution {
public:
    // Time complexity: O(nlogn)
    // Approach: Greedy Algo - Choose the best option and move on, no backtracking/recursive.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start >= prevEnd) {
                prevEnd = end;
            } else {
                res++;
                // Keep the interval with the smaller end
                prevEnd = min(end, prevEnd);
            }
        }
        return res;
    }
};