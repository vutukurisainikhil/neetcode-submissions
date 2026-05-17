class Solution {
   public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<uint>> dp(m + 1, vector<uint>(n + 1, 0));

        // Base case: empty t can be formed from any prefix of s in exactly 1 way (skip everything).
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Two possibilities: 1. skip s[i-1]  2. if chars match, use s[i-1] for t[j-1]
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};