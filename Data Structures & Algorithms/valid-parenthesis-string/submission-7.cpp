class Solution {
public:
    // Trick: track the RANGE of possible open-paren counts, not a single count.
    //   - open = min possible open count (treat every '*' as ')' or empty)
    //   - close = max possible open count (treat every '*' as '(')
    // Each '*' widens the range; '(' and ')' shift both ends together.
    // Valid iff some count in [open, close] ends at 0 — i.e., open == 0 at the end.
    //
    // Time: O(n), Space: O(1).
    bool checkValidString(string s) {
        int open = 0, close = 0;
        for (int i = 0; i < s.size(); i++) {
            open += s[i] == '(' ? 1 : -1; // +1 for open, remaining -1 for  ')' or '*'
            close += s[i] == ')' ? -1 : 1; // -1 for close, remaining +1 for  '(' or '*'
            if (close < 0)
                break; // more close brackets, so invalid
            open = max(open, 0); // chances for more stars so clamp to 0.
        }
        return open == 0; // All matches, then true.
    }
};