class Solution {
public:
    // TimeComplexity: O(n)
    int numDecodings(string s) {
        int n = s.size();
        vector<int> count(n + 1, 0);
        count[0] = 1;
        count[1] = 1;
        if(s[0] == '0') // invalid case
            return 0;
        for(int i = 2; i <= n; i++) {
            if(s[i - 1] > '0')
                count[i] += count[i - 1];
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
                count[i] += count[i - 2];
        }
        return count[n];
    }
};