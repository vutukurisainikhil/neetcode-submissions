class DSU {
    vector<int> p, rnk;

public:
    DSU(int n) : p(n), rnk(n, 0) { 
        for(int i=0;i<n;i++){
            p[i]=i;
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
        if (x == y) {
            return false;
        }
        if (rnk[x] < rnk[y]) {
            p[x] = y;
        } else if (rnk[y] < rnk[x]) {
            p[y] = x;
        } else {
            p[y] = x;
            rnk[x]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU* g = new DSU(edges.size() + 1);
        for (auto e : edges) {
            if (!g->unioun(e[0], e[1])) {
                return {e[0], e[1]};
            }
        }
        return {-1, -1};
    }
};