class Solution {
   public:
    /* Test String: cbabc
    Logic:
    1. for finding palindrome, pass through the loop, left (increment) & right pointer (decrement)
    to check palindrome length and string.
    2. for Even palindrome: initialise left & right with same index.
    3. for Odd palindrome: initialise left & right with same index,index+1.
    */
    // Time Complexity: O(n^2)
    string longestPalindrome(string s) {
        string res("");
        int strlen = 0;
        for (int i = 0; i < s.length(); ++i) {
            // odd palindrome
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > strlen) {
                    strlen = r - l + 1;
                    res = s.substr(l, strlen);
                }
                l--;
                r++;
            }

            // even palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > strlen) {
                    strlen = r - l + 1;
                    res = s.substr(l, strlen);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};