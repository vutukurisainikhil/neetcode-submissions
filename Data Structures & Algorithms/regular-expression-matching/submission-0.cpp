class Solution {
public:
    // Regular Expression Matching (LC 10).
    // Pattern supports: '.' (any single char) and '*' (zero or more of preceding char).
    // 
    // DP: dp[i][j] = "does s[i..] match p[j..]?"
    // We fill bottom-up (i and j from the END toward 0), so when we compute dp[i][j],
    // the subproblems dp[i+1][j], dp[i][j+2], dp[i+1][j+1] are already known.
    //
    // Two cases per cell:
    //   1. Next pattern char is '*' (p[j+1] == '*'):
    //      - Zero matches:  use dp[i][j+2]  (skip "c*" entirely)
    //      - One+ matches:  current char matches AND dp[i+1][j]  (consume s[i], keep "c*")
    //   2. Otherwise: current chars must match AND the rest must match (dp[i+1][j+1]).
    //
    // Time: O(m * n), Space: O(m * n) — m = |s|, n = |p|.
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        // dp[i][j] = true iff s[i..] matches p[j..].
        // Extra row/column for the "both empty" base case.
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern.
        dp[m][n] = true;
        
        // Fill table from bottom-right to top-left.
        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                // Does s[i] match the current pattern char p[j]?
                // Guard i < m because we still process i == m (empty suffix of s),
                // which can match patterns like "a*b*c*".
                bool firstMatch = (i < m) && (s[i] == p[j] || p[j] == '.');
                
                // Case 1: pattern has a '*' after the current char.
                if (j + 1 < n && p[j + 1] == '*') {
                    // Either: skip "c*" entirely (zero matches),
                    //     or: consume one s char and keep the "c*" for more matches.
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                }
                // Case 2: no '*' — chars must match and rest must match.
                else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        
        return dp[0][0];
    }
};