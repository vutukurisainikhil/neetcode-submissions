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
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;
        for (auto& edge : edges) {
            // connecting the edges only. the remaining ones are not-connected.
            if (dsu.unioun(edge[0], edge[1])) {
                res--;
            }
        }
        return res;
    }
};