class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i , j, grid, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int& area){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return;
        }

        if(grid[i][j] == 1){
            area += 1;
            grid[i][j] = 0;
        }

        dfs(i+1, j, grid, area);
        dfs(i-1, j, grid, area);
        dfs(i, j-1, grid, area);
        dfs(i, j+1, grid, area);
    }
};