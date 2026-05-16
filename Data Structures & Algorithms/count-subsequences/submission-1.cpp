class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<uint>> dp(m + 1, vector<uint>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // two possibilities: 1. skip 2. if same char.
                dp[i][j] = dp[i + 1][j]; 
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};