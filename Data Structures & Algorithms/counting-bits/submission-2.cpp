class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num != 0) {
                // results num value to (nums-1) & reduces a set bit.
                num &= (num - 1);
                res[i]++; // count one set bit, as reduced.
            }
        }
        return res;
    }
};