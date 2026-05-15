class Solution {
public:
    /* Logic: find all rotten tomato's indexes into queue and apply BFS traversal with incrementing time+=1;
    */
    int max_time=-1;
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS traversal for identify time to rotten oranges.
        BFS(grid, -1);
        // check for identifying, whether grid is having all zero's or not
        bool not_zeros_grid = false;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==1){
                    return -1;
                }
                if(grid[i][j]==2){
                    not_zeros_grid = true;
                }
            }
        }
        return (not_zeros_grid)? max_time:0;
    }
    // BFS traversal
    void BFS(vector<vector<int>> &grid, int time){
        queue<pair<int,int>> q;
        // filling all rotten tomato's into queue, so we can check neighbour's
        fill_rotten_queue(grid, q);
        while(!q.empty()){
            time++; // incrementing time
            int k = q.size();
            while(k--){
                pair<int,int> m = q.front();
                q.pop();
                // if valid, updating queue and setting grid value to 2
                if(is_valid(m.first+1,m.second, grid)){
                    q.push({m.first+1,m.second});
                    grid[m.first+1][m.second] = 2;
                }
                if(is_valid(m.first-1,m.second, grid)){
                    q.push({m.first-1,m.second});
                    grid[m.first-1][m.second] = 2;
                }
                if(is_valid(m.first,m.second-1, grid)){
                    q.push({m.first,m.second-1});
                    grid[m.first][m.second-1] = 2;
                }
                if(is_valid(m.first,m.second+1, grid)){
                    q.push({m.first,m.second+1});
                    grid[m.first][m.second+1] = 2;
                }
            }
            max_time = max(time, max_time);
        }
    }
    // checking valid indexes & grid[row][col]==1
    bool is_valid(int row, int col, vector<vector<int>> &grid){
        if(row>=0 && col>=0 && row<=grid.size()-1 && col<=grid[row].size()-1 && grid[row][col]==1){
            return true;   
        }
        return false;
    }
    
    // filling rotten tomato's indexes into queue
    void fill_rotten_queue(vector<vector<int>> &grid, queue<pair<int,int>> &q){
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
    }
};