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
        int lo = 0 , hi = 0;
        for(auto c: s){
            lo += c == '(' ? 1: -1;
            hi += c == ')' ? -1: 1;
            if(hi <0){
                return false;
            }
            lo = max( lo, 0);
        }
        return lo==0;
    }
};