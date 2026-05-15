class graph {
    int* p;

public:
    graph(int n) {
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    bool unioun(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y)
            // Already they are connected, then this edge is redundant.
            return false;

        p[x] = y;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph* g = new graph(n);
        for (int i = 0; i < n; i++) {
            if (!g->unioun(edges[i][0] - 1, edges[i][1] - 1)) {
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }
};