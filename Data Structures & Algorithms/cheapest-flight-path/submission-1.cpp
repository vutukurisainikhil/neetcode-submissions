class Solution {
public:
    // Cheapest Flights Within K Stops (LC 787).
    // Approach: Bellman-Ford-style BFS, layer by layer.
    //   - Each BFS "layer" represents using one more edge (one more stop).
    //   - Run for at most k+1 layers (k stops = k+1 edges).
    //   - Relax: if a shorter path to a neighbor is found, update and enqueue.
    // Why not Dijkstra? Dijkstra is greedy on min cost, but here we're bounded by
    // edge count (stops), not just cost — a "longer but cheaper" path may exceed
    // the stop limit. Bellman-Ford-by-layers naturally respects the stop bound.
    //
    // Time: O(k * E)  — k+1 layers, each layer scans every edge at most once.
    // Space: O(n + E) — adjacency list + queue (bounded by nodes per layer).
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Build adjacency list. flight = [from, to, price].
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});  // {neighbor, price}
        }
        
        // Step 2: BFS by layers. Queue holds {node, cost-so-far-to-reach-it}.
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        // Best cost found to reach each node (under the stop limit so far).
        vector<int> minCost(n, INT_MAX);
        
        // Step 3: Process at most k+1 layers (k stops allowed = k+1 edges max).
        int stops = 0;
        while (!q.empty() && stops <= k) {
            // Process this entire layer before moving to the next.
            // This is the "layer-by-layer" structure that bounds total edges used.
            int size = q.size();
            while (size--) {
                auto [currNode, cost] = q.front();
                q.pop();
                
                // Relax each outgoing edge: if going through currNode gives a
                // cheaper path to neighbor, update and enqueue for the next layer.
                for (const auto& [neighbor, price] : adj[currNode]) {
                    if (cost + price < minCost[neighbor]) {
                        minCost[neighbor] = cost + price;
                        q.push({neighbor, minCost[neighbor]});
                    }
                }
            }
            stops++;
        }
        
        // Step 4: Return the cheapest cost found to dst within k stops, or -1 if unreachable.
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};