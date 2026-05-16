class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (s3.length() != m + n) 
            return false;

        // dp[j] after row i = "can s3[0..i+j-1] be formed using s1[0..i-1] and s2[0..j-1]?"
        // We roll through rows i = 0..m, updating dp in place.
        // Before update: dp[j] = "above" (old row), dp[j-1] = "left" (already updated this row).
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // base case: empty + empty matches s3's empty prefix

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) continue;  // base case already set

                bool fromS1 = (i > 0) && dp[j] && s1[i - 1] == s3[i + j - 1];  // came from "above"
                bool fromS2 =
                    (j > 0) && dp[j - 1] && s2[j - 1] == s3[i + j - 1];  // came from "left"

                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[n];
    }
};