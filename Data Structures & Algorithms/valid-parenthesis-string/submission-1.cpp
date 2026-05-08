class Solution {
public:
// leftMin → the minimum possible number of unmatched '('
// leftMax → the maximum possible number of unmatched '('
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            
            if (leftMax < 0) {
                // too many closing parentheses
                return false;
            }
            if (leftMin < 0) {
                // we can treat extra closings as empty
                leftMin = 0;
            }
        }
        return leftMin == 0;
    }
};