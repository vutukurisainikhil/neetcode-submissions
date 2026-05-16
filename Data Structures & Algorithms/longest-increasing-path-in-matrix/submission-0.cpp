class Solution {
    
public:
    // Time complexity: O(m∗n) as we use dp
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans = max(ans, dfs(matrix, i, j,  INT_MIN, dp));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int preval, vector<vector<int>>& dp){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= preval){
            return 0;
        }
        // Already did earlier and cached it, so re-using it.
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int res_a = dfs(matrix, i+1, j, matrix[i][j], dp);
        int res_b = dfs(matrix, i-1, j, matrix[i][j], dp);
        int res_c = dfs(matrix, i, j+1, matrix[i][j], dp);
        int res_d = dfs(matrix, i, j-1, matrix[i][j], dp);
        int ans =  max(res_a, max(res_b, max(res_c, res_d))) + 1;
        // cache as following dp.
        dp[i][j] = ans;
        return ans;
    }
};
