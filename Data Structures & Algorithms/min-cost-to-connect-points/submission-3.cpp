class Solution {
   public:
    // Prims Algorithm
    int manhattan(vector<int>& a, vector<int>& b) { return abs(a[0] - b[0]) + abs(a[1] - b[1]); }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        // storing in adj = {from_point,{to_point,dis}}
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                adj[i].push_back({j, manhattan(points[i], points[j])});
                adj[j].push_back({i, manhattan(points[j], points[i])});
            }
        }
        int cost = 0;
        // Sort in Ascending order.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0 /*dis*/, 0 /*from_point*/});
        vector<int> visited(points.size(), 0);
        while (!pq.empty()) {  // O(n)*O(nlogn)
            auto val = pq.top();
            pq.pop();
            int dis = val.first;
            int point = val.second;
            if (visited[point] == 1) {
                continue;
            }
            visited[point] = 1;
            cost += dis;
            for (auto itr : adj[point]) {
                pq.push({itr.second /*dis*/, itr.first /*to_point*/});
            }
        }
        return cost;
    }
};