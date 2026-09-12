class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int curr_area = 0;
                    dfs(grid, i, j, curr_area);
                    area = max(area, curr_area);
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int& curr_area){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return 0;
        }
        if(grid[i][j]==0){
            return 0;
        }
        grid[i][j] = 0;
        curr_area += 1;
        dfs(grid, i+1, j, curr_area);
        dfs(grid, i-1, j, curr_area);
        dfs(grid, i, j+1, curr_area);
        dfs(grid, i, j-1, curr_area);
        return curr_area;
    }
};
