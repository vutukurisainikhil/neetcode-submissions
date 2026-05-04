class Solution {
   public:
    // Time complexity: O(n⋅m⋅k)
    // Space complexity:O(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // we mark as true every index that we managed to segment so far
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                // from dp[0] = true && we try to exactly break word and make it as true.
                if ((dp[j]) && (std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) !=
                                wordDict.end())) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();

        /**
         // using maps instaed of find() function

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_map<string, bool> mp;

        for (int i = 0; i < wordDict.size(); i++)
            mp[wordDict[i]] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((dp[j]) && mp[s.substr(j, i - j)]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
        **/
    }
};