class Solution {
public:
    // Time O(n), Space O(1)
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) count[task - 'A']++;

        int maxFreq = *max_element(count.begin(), count.end());
        int maxFreqTasks = count_if(count.begin(), count.end(),
                                    [maxFreq](int c) { return c == maxFreq; });

        // Two candidates for the answer:
        // 1. Skeleton-based lower bound: (maxFreq - 1) * (n + 1) + maxFreqTasks
        // 2. Just the total task count (when there's enough variety to never idle)
        int skeleton = (maxFreq - 1) * (n + 1) + maxFreqTasks;
        return max(skeleton, (int)tasks.size());
    }
};