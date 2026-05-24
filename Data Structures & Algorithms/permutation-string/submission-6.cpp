class Solution {
public:
    // Sliding window of size |s1| over s2. The window is a permutation of s1
    // iff the two letter-frequency arrays are equal. Compare 26-element arrays
    // each slide -> O(1) comparison, O(n) total.
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> s1Count(26, 0), windowCount(26, 0);
        int k = s1.size();

        // Build s1's frequency and the first window's frequency in one pass.
        for (int i = 0; i < k; i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }
        if (s1Count == windowCount)
            return true; // check before sliding

        // Slide one character at a time: add the new right char, drop the old
        // left char.
        for (int r = k; r < (int)s2.size(); r++) {
            windowCount[s2[r] - 'a']++; // add new char entering window
            windowCount[s2[r - k] -'a']--; // remove char leaving window (k positions back)
            if (s1Count == windowCount)
                return true;
        }
        return false;
    }
};