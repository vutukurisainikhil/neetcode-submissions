class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        minHeap.push({grid[0][0] /*val*/, 0 /*row*/, 0 /*col*/});
        visit.insert({0 /*row*/, 0 /*col*/});

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            if (r == N - 1 && c == N - 1) {
                return t;
            }
            for (const auto& dir : directions) {
                int neiR = r + dir[0], neiC = c + dir[1];
                if (neiR < 0 || neiC < 0 || neiR == N || neiC == N ||
                    visit.count({neiR, neiC})) {
                    continue;
                }
                visit.insert({neiR, neiC});
                // from start to end path, find the max t.
                minHeap.push({max(t, grid[neiR][neiC]), neiR, neiC});
            }
        }

        return N * N;
    }
};