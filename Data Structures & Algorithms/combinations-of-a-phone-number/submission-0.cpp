class Solution {
   public:
    /*
        By Backtracking (with DFS), finding all combinations of letters formed from digits.
    */
    void solve(string digit, int idx, string output, vector<string>& ans, string map[]) {
        //(ex: digit = "23";)  if constructed ans of same digits.length();
        if (idx >= digit.length()) {
            ans.push_back(output);
            return;
        }

        int number = digit[idx] - '0';
        string value = map[number];

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, idx + 1, output, ans, map);  // increment index++
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }
        string output;
        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        solve(digits, index, output, ans, map);
        return ans;
    }
};