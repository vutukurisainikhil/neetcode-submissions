class Solution {
public:
    // For each query q, find the smallest interval [l, r] containing q (l <= q <= r).
    //
    // Approach: offline sweep — sort queries and process them in order, maintaining
    // a heap of "currently active" intervals (those whose start <= current query).
    //   - Process queries in ascending order.
    //   - As q grows, add intervals with start <= q to the heap (sweep them in).
    //   - Lazily evict intervals that have ended (r < q) from the heap top.
    //   - The heap's min-by-size element is the answer for this q.
    //
    // Why a min-heap by interval size? We want the smallest interval containing q.
    //
    // Time: O((n + m) log(n + m)), Space: O(n + m). n = intervals, m = queries.
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start so we can sweep them in as queries grow.
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        // Sort queries — but keep the original order via a result map (queries can have duplicates).
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Map each query value to its answer. Used to look up answers in original query order.
        map<int, int> res;
        
        // Min-heap of {size, end}, ordered by size (smallest first).
        // Lexicographic: size primary, end secondary.
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        int i = 0;  // pointer into sorted intervals
        for (int q : sortedQueries) {
            // Sweep in all intervals that have started by this query.
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i][1];
                minHeap.push({r - l + 1, r});  // {size, end}
                i++;
            }

            // Lazy eviction: discard intervals whose end is before q (they no longer contain q).
            // We only need to clean the top, because anything not at the top will be
            // evicted later when it becomes the smallest.
            while (!minHeap.empty() && minHeap.top()[1] < q) {
                minHeap.pop();
            }

            // The remaining smallest interval at the top contains q (or heap is empty).
            res[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }

        // Map answers back to original query order.
        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = res[queries[j]];
        }
        return result;
    }
};