class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> res;
        backtrack("", res, 0,0, n);
        return res;
    }
    
    void backtrack(string answer, vector<string> &res, int open, int end, int n){
        // genetrating n pair of parentheses
        // when adding open or close brackets, if n*2==answer.length(), append it to result.
        if(n*2 == answer.length()){
            res.push_back(answer);
        }
        // adding open brackets "(", if open < n.
        if(open<n){
            answer.append("(");
            backtrack(answer, res, open+1, end, n);
            answer.pop_back();
        }
        // if end < open, then we havent closed all opened brackets. so close all.
        if(end<open){
            answer.append(")");
            backtrack(answer, res, open, end+1, n);
            answer.pop_back();
        }
    }
};