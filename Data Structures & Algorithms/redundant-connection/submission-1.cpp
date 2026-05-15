class DSU {
    vector<int> p, rnk;

public:
    DSU(int n) : p(n), rnk(n, 0) { iota(p.begin(), p.end(), 0); }

    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    bool unite(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y)
            return false; // already connected, so edge is redundant.
        if (rnk[x] < rnk[y])
            p[x] = y;
        else if (rnk[x] > rnk[y])
            p[y] = x;
        else {
            p[y] = x;
            rnk[x]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 1);
        for (auto& e : edges) {
            if (!dsu.unite(e[0], e[1]))
                return e;
        }
        return {};
    }
};