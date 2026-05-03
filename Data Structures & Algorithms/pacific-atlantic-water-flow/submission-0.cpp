class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> visitedPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> visitedAtlantic(rows, vector<bool>(cols, false));

        for(int col=0; col<cols; col++){
            markAllReachable(0 /*const*/, col, heights, visitedPacific);
            markAllReachable(rows-1/*const*/, col, heights, visitedAtlantic);
        }

        for(int row = 0; row<rows; row++){
            markAllReachable(row, cols-1/*const*/, heights, visitedAtlantic);
            markAllReachable(row, 0/*const*/, heights, visitedPacific);
        }
        // both pacafic and atlantic is reachable, then add index to res;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visitedPacific[i][j] && visitedAtlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    void markAllReachable(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        if(visited[row][col])
            return;
        /**
        A cell can reach an ocean if water can flow from that cell to the ocean (downhill/flat).
Reverse it: start from the ocean borders and move uphill/flat (to neighbors with height >= current).
If you can climb from the ocean to a cell, then that cell can flow down to that ocean.
        **/
        visited[row][col] = true;
        for(auto d:dir){
            int x = row+d[0];
            int y = col+d[1];
            if(x>=0 && x<heights.size() && y>=0 && y<heights[0].size() 
                    && heights[x][y] >= heights[row][col]){
                // water flow can happen to index(x,y). so dfs it.
                markAllReachable(x, y, heights, visited);
            }
        }
    }

};