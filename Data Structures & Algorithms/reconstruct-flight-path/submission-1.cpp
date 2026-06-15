class Solution {
   public:
    // Time complexity: O(ElogE)
    // Space complexity:O(E)
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Hierholzer's algorithm (iterative):
        //   - Greedy DFS, always picking the lexicographically smallest next airport.
        //   - Append to result in POST-ORDER (when an airport has no outgoing tickets left).
        //   - Reverse at the end to get traversal order.
        // Why post-order? Dead ends finish first and settle into the result,
        // so greedy can't get stuck — the main path is always resumable via the stack.

        // graph[from] = sorted multiset of destinations (multiset = auto-sorted, allows duplicates)
        unordered_map<string, multiset<string>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        vector<string> res;
        if (tickets.empty()) return res;

        // Stack holds the current path. Top = airport we're currently "at".
        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            const string& curr = st.top();

            if (graph[curr].empty()) {
                // No tickets out — this airport is done. Append (post-order) and backtrack.
                res.push_back(curr);
                st.pop();
            } else {
                // Take the smallest-destination ticket and fly there.
                st.push(*graph[curr].begin());
                graph[curr].erase(graph[curr].begin());
            }
        }

        // res is in finish order (post-order). Reverse to get travel order.
        reverse(res.begin(), res.end());
        return res;
    }
};