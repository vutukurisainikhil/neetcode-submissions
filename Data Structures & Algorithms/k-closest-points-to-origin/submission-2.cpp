class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min-heap ordered by squared distance
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (auto& p : points) {
            int dist = p[0] * p[0] + p[1] * p[1];
            minHeap.push({dist, p[0], p[1]});
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            auto& top = minHeap.top();
            res.push_back({top[1], top[2]});
            minHeap.pop();
        }
        return res;
    }
};