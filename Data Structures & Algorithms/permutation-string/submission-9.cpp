class Solution {
public:
    // Sliding window of size |s1| over s2. The window is a permutation of s1
    // iff the two letter-frequency arrays are equal.
    // Time O(n), Space O(1).
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Freq(26, 0), windowFreq(26, 0);
        int k = s1.size();

        // Build s1's frequency and the first window's frequency in one pass.
        for (int i = 0; i < k; i++) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }
        if (s1Freq == windowFreq) 
            return true;

        // Slide one character at a time: add new right char, drop old left char.
        for (int r = k; r < (int)s2.size(); r++) {
            windowFreq[s2[r] - 'a']++;       // char entering window
            windowFreq[s2[r - k] - 'a']--;   // char leaving window
            if (s1Freq == windowFreq) 
                return true;
        }
        return false;
    }
};