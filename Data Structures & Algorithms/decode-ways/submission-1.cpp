class Solution {
public:
    // TimeComplexity: O(n)
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp_count(n + 1, 0);
        dp_count[0] = 1;
        dp_count[1] = 1;
        if(s[0] == '0') // invalid case
            return 0;
        for(int i = 2; i <= n; i++) {
            if(s[i - 1] > '0')
                dp_count[i] += dp_count[i - 1];
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
                dp_count[i] += dp_count[i - 2];
        }
        return dp_count[n];
    }
};