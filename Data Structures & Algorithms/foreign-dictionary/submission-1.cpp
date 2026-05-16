class Solution {
   public:
    // Alien Dictionary (Foreign Dictionary).
    // Approach: derive ordering constraints from adjacent word pairs,
    //          then topological sort using Kahn's algorithm (BFS).
    // Time: O(N), Space: O(1) — N = total characters across all words; alphabet is bounded.
    string foreignDictionary(vector<string>& words) {
        // Step 1: Initialize every unique character as a graph node with indegree 0.
        // Even chars with no edges must appear in the final ordering.
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (const string& w : words) {
            for (char c : w) {
                adj[c];           // ensure key exists (default-constructs empty set)
                indegree[c] = 0;  // ensure key exists with 0
            }
        }

        // Step 2: Build edges by comparing consecutive word pairs.
        // For each adjacent pair (w1, w2), the FIRST differing character tells us
        // w1[j] must come BEFORE w2[j] in the alien alphabet → edge w1[j] → w2[j].
        // Characters after the first difference give no ordering info.
        for (int i = 0; i < words.size() - 1; i++) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());

            // Invalid case: w1 is longer and w2 is a prefix of w1 (e.g., "abcd" before "abc").
            // No valid ordering can exist — a longer word can't come before its own prefix.
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }

            // Scan for the first character that differs.
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    // Found it: w1[j] must come before w2[j].
                    // Add edge only if not already present (avoid double-counting indegree).
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;  // No more info from this pair — subsequent chars don't constrain order.
                }
            }
        }

        // Step 3: Kahn's algorithm — BFS starting from nodes with indegree 0.
        queue<char> q;
        for (auto& [c, deg] : indegree) {
            if (deg == 0) q.push(c);
        }

        // Step 4: Process nodes in topological order.
        // Each time we pop a node, we've finalized its position in the result.
        // Decrement neighbors' indegrees; enqueue any that hit 0.
        string res;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            for (char neighbor : adj[c]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we couldn't include every character, there's a cycle → no valid ordering.
        return res.size() == indegree.size() ? res : "";
    }
};