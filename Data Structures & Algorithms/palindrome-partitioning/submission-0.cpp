class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, res, curr, 0);
        return res;
    }

    void backtrack(string s, vector<vector<string>>& res, vector<string>& curr, int idx){
        if(idx == s.size()){
            res.push_back(curr);
            return;
        }
        for(int i = idx; i<s.size(); i++){
            if(ispalindrome(idx, i, s)){
                curr.push_back(s.substr(idx, i-idx+1));
                backtrack(s, res, curr, i+1);
                curr.pop_back();
            }
        }
    }

    bool ispalindrome(int left, int right, string s){
        while(left<right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};