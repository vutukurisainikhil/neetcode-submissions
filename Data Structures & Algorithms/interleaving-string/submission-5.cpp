class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (s3.length() != m + n) return false;

        vector<bool> dp(n + 1, false);
        dp[0] = true;  // base case: empty + empty matches s3's empty prefix

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) continue;  // base case already set
                // In Matrix, s1 is at top so, d[j] is came from "above"
                bool fromS1 = (i > 0) && dp[j] && s1[i - 1] == s3[i + j - 1];
                // d[j-1] came from "left"
                bool fromS2 = (j > 0) && dp[j - 1] && s2[j - 1] == s3[i + j - 1];

                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[n];
    }
};