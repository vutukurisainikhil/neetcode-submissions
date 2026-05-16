class Solution {
public:
    // Dijkstra's Algo - Finding distance to all nodes form 'x' point.
    // Firstly finding shortance distance from b/w all
    // nodes. then checking the max time taken,so that it is the network time
    // taken to send message.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Building adj list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back(
                std::make_pair(times[i][1], times[i][2]));
        }
        // shortest distance b/w all nodes
        vector<int> dis(n + 1, INT_MAX);
        // minHeap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // starting with k
        pq.push({0, k});
        dis[k] = 0;
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            int source = curr.second;
            for (int i = 0; i < adj[source].size(); i++) {
                int weight = adj[source][i].second;
                int destination = adj[source][i].first;
                // Dijakstra's : Always look for shortest distance.
                if (dis[destination] > dis[source] + weight) {
                    dis[destination] = dis[source] + weight;
                    pq.push({dis[destination], destination});
                }
            }
        }
        // Logic to find max distance for any node,
        // which will be the count to send network message.
        int count = INT_MIN;
        for (int i = 1; i <= n; i++) {
            count = max(count, dis[i]);
        }
        return count == INT_MAX ? -1 : count;
    }
};