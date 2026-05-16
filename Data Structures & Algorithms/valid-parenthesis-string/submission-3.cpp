class Solution {
public:
    // Trick: track the RANGE of possible open-paren counts, not a single count.
    //   - lo = min possible open count (treat every '*' as ')' or empty)
    //   - hi = max possible open count (treat every '*' as '(')
    // Each '*' widens the range; '(' and ')' shift both ends together.
    // Valid iff some count in [lo, hi] ends at 0 — i.e., lo == 0 at the end.
    //
    // Time: O(n), Space: O(1).
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (int i = 0; i < s.size(); i++) {
            lo += s[i] == '(' ? 1 : -1; // +1 for open, remaining -1 for  ')' or '*'
            hi += s[i] == ')' ? -1 : 1; // -1 for close, remaining +1 for  '(' or '*'
            if (hi < 0)
                break; // more close brackets, so invalid
            lo = max(lo, 0); // chances for more stars so clamp to 0.
        }
        return lo == 0;
    }
};