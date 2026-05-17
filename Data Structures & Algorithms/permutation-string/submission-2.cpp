class Solution {
public:
    // Sliding window of size |s1| over s2. Maintain letter frequencies for both.
    // Trick: track `matches` = count of letters (0..25) where s1Count == s2Count.
    // When matches == 26, all letters agree → window is a permutation of s1.
    // Each slide updates `matches` in O(1) by re-checking only the two changed letters.
    //
    // Time: O(n), Space: O(1).
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        // Build frequencies for s1 and the first window of s2.
        vector<int> s1Count(26, 0), s2Count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Initial match count (includes letters where both are 0).
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) matches++;
        }

        // Slide the window with size of s1.length().
        int l = 0;
        // start with s1.length().
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) return true;

            // Add s2[r] to the window.
            int idx = s2[r] - 'a';
            s2Count[idx]++;
            if (s1Count[idx] == s2Count[idx]) matches++;          // became equal
            else if (s1Count[idx] + 1 == s2Count[idx]) matches--; // just broke a match

            // Remove s2[l] from the window.
            idx = s2[l] - 'a';
            s2Count[idx]--;
            if (s1Count[idx] == s2Count[idx]) matches++;          // became equal
            else if (s1Count[idx] - 1 == s2Count[idx]) matches--; // just broke a match
            l++;
        }
        return matches == 26;
    }
};