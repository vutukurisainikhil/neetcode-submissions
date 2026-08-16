class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        // find all rotten oranges and count fresh ones
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == 2)      
                    q.push({r, c});
                else if (grid[r][c] == 1) 
                    fresh++;
        if (fresh == 0) return 0;             // nothing to rot
        int time = 0;
        int dirs[] = {0, 1, 0, -1, 0};       // right, down, left, up

        while (!q.empty()) {
            int size = q.size();
            time++;
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d], nc = c + dirs[d + 1];
                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols
                        && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;     // rot it
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        // -1 if unreachable fresh remains
        return fresh == 0 ? time - 1 : -1;   
    }
};