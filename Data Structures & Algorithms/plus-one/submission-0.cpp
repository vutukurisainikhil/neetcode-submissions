class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 0;
        for (int i = 0; i < digits.size(); i++) {
            int x = digits[i];
            if (i == 0) {
                x += 1; // add only one.
            } else if (carry > 0) {
                x += carry;
            }
            digits[i] = x % 10;
            (x >= 10) ? carry = x / 10 : carry = 0;
            if (carry == 0) {
                break;
            }
        }
        if (carry > 0) {
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};